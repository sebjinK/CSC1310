/************************************************************
* Name: list.h                                              *
* Date: 3/22/2023                                           *
* Author: Johnathan Leth                                    *
* Purpose: creates the list class to hold listnodes and     *
* makes the functions used to manipulate and sort the list  *
* File needed for: driver.cpp                               *
************************************************************/
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

//template List class that stores listNodes and their pointers
template <typename T>
class List {
    private: //private list objects
        struct listNode {
            //listNodes stored value and pointers to the previous and next node
            T value;
            listNode *nextNode;
            listNode *prevNode;

        };

        //creates head and tail pointers for the list
        listNode *head;
        listNode *tail;

        //private function prototypes
        void print(listNode*);
        listNode* mergeSort(listNode* start, listNode* end);
        listNode* merge(listNode* head1, listNode* head2);
        listNode* split(listNode* start, listNode* end);

        //extra credit functions
        void swap(listNode* swapNode1, listNode* swapNode2);
        listNode* selectionSort(listNode* start);

        //swap is three lines
        //selection sort two while loops nested

    public: //public function prototypes
        List() { //constructor
            head = NULL;
            tail = NULL;
        }
        ~List();
        void print();
        void append(T);
        void mergeSort();
        void selectionSort();
};

//private functions

/*
name: print
purpose: displays all elements from the list
*/
template <typename T>
void List<T>::print(listNode* start) {
    listNode *currNode;
    currNode = start;

    //while currNode has a value output that value and move to the next node
    while(currNode != NULL) {
        cout << *(currNode->value) << endl;
        currNode = currNode->nextNode;
    }

}

/*
name: mergesort
purpose: calls split, merge, and recursivelly calls mergeSort to sort data
*/
template <typename T>
typename List<T>::listNode* List<T>::mergeSort(listNode* start, listNode* end) {
    listNode *mid;
    
    //if list is empty return empty list
    if((start == NULL) || (start->nextNode == NULL)) {
        return start;
    }

    //cout << "Mergesort success";lll
    //finds the midpoint of the list
    mid = split(start, end);

    //recursivelly calls mergeSort for the two halves of the list
    //cout << "before recursion";
    start = mergeSort(start, mid->prevNode); //i'm a function call that causes seg faults!
    //cout << "left success";
    mid = mergeSort(mid, end);
    //cout << "right success";

    //returns the merged lists
    return merge(start, mid);
}


/*
name: merge
purpose: takes the heads of two linked lists and merges them together
*/
template <typename T>
typename List<T>::listNode* List<T>::merge(listNode* head1, listNode* head2) {
    //if list one is empty just return list two
    if(head1 == NULL) {
        return head2;
    }
    //if list two is empty return list one
    if(head2 == NULL) {
        return head1;
    }

    //cout << "Merge success";
    //cout << head1->value->getPopulation();

    //if the population of the head of the first list is greater make it the head of the new list
    if(*(head1->value) > *(head2->value)) {
        head1->nextNode = merge(head2, head1->nextNode);
        head1->nextNode->prevNode = head1;
        head1->prevNode = NULL;
        return head1;
    }
    //otherwise make the head of the second list the head of the new list
    else {
        head2->nextNode = merge(head1, head2->nextNode);
        head2->nextNode->prevNode = head2;
        head2->prevNode = NULL;
        return head2;
    }
}
/*
name: split
purpose: takes the head and tail of a linked list and splits it in half
*/
template <typename T>
typename List<T>::listNode* List<T>::split(listNode* start, listNode* end) {

    listNode *currNode;

    //cout << "split success";

    //while the list is longer than two elements continue iterating
    while(start != end && start->nextNode != end) {
        start = start->nextNode;
        end = end->prevNode;
    }

    //sets currNode to the found midpoint
    currNode = start->nextNode;
    start->nextNode = NULL;
    //cout << "loop?";

    return currNode;
        
}

/*
name: swap
purpose: take the data from two nodes in a linked list and swap them
*/
template <typename T>
void List<T>::swap(listNode* swapNode1, listNode* swapNode2) {
    //swaps the two nodes using a placeholder node
    listNode* tmpNode;
    tmpNode = new listNode;
    
    //sets tmpNode's value to swapNode1's value
    tmpNode->value = swapNode1->value;

    //using tmpNode switches the values between swapNode1 and swapNode2
    swapNode1->value = swapNode2->value;
    swapNode2->value = tmpNode->value;
    
    //discarded more complicated swap function
    /*
    listNode* tmpNode = swapNode1;
    swapNode1->nextNode = swapNode2->nextNode;
    swapNode1->prevNode = swapNode2->prevNode;

    swapNode2->nextNode = tmpNode->nextNode;
    swapNode2->prevNode = tmpNode->prevNode;
    */
}


/*
name: selection sort
purpose: sorts the county data using selection sort and the swap function
*/
template <typename T>
typename List<T>::listNode* List<T>::selectionSort(listNode* start) {
    listNode* tmpNode = start;
  
    //while tmpNode holds a value keep looping
    while (tmpNode != NULL) {
        listNode* currNode = tmpNode;
        listNode* compareNode = tmpNode->nextNode;
  
        //while compareNode holds a value keep looping
        while (compareNode != NULL) {
            //if the value of currNode is greater than compareNode then set currNode to compareNode 
            if (*(currNode->value) > *(compareNode->value)) {
                currNode = compareNode;
            }

            //move compareNode to the next node in the list
            compareNode = compareNode->nextNode;
        }
        
        //call the swap function passing in tmpNode and currNode
        swap(tmpNode, currNode);

        //move tmpNode to the next node in the list
        tmpNode = tmpNode->nextNode;
    }

    return start;
}

//public functions

/*
name: ~List
purpose: goes through the double linked list and deletes each element
*/
template <typename T>
List<T>::~List() {
    listNode *currNode; //treversing node
    listNode *delNode; //deletion node

    //sets the currNode to head
    currNode = head;

    //while the list still has nodes keep running
    while(currNode != NULL) {
        //sets delNode to currNode and indexes currNode forward
        delNode = currNode;
        currNode = currNode->nextNode;

        //deletes the delNode
        delete delNode;
    }

    cout << "\n\nAll nodes from the list have been deleted.\n";
}


/*
name: print()
purpose: calls the private print function passing head as an argumnet
*/
template <typename T>
void List<T>::print() {
    print(head);
    //cout << "\npublic print\n";
}


/*
name: append
purpose: adds a new county to the end of the double linked list
*/
template <typename T>
void List<T>::append(T newCounty) 
{
    listNode *newNode;
    newNode = new listNode;
    // 
    newNode->value = newCounty;
    // head->prev = NULL;
    //If there is not already a node make the new node the start of the list
    if(!head) { //if no nodes in the list
        //makes a new linklist with the new node at the start
        head = newNode;
        tail = newNode;
    }
    //If there is already a node put this new node at the end of it
    else {
        //makes the new node the tail of the list
        if(head == tail) { // only one node in the list currently
            head->nextNode = tail; 
        }
        //continues with the appending process
        head->prevNode = NULL; // make a enclosed list
        tail->nextNode = newNode; // tail's next node is made into the newNode
        newNode->prevNode = tail; // connect the list together
        tail = newNode; // set a new tail 
        tail->nextNode = NULL; // enclose the list within NULL   
    //I'm using this to test for edge cases
    //cout << "If you can somehow find this in both this program and Lab 4 I am doing something wrong." << endl;
    } 
}

/*
name: mergeSort()
purpose: calls the private  mergeSort functions passing in head & tail and finds the new head & tail
*/
template <typename T>
void List<T>::mergeSort() {
    //sets head equal to the new head returned by mergeSort
    head = mergeSort(head, tail);
    

    //sets currNode equal to head
    listNode* currNode = head;

    //using currNode traverses to the end of the list to find the new tail
    while(currNode->nextNode != NULL) {
        currNode = currNode->nextNode;
    }

    //sets tail equal to the currNode
    tail = currNode;

    //cout << "\npublic mergesort\n";
    //cout << mergeSort(head, tail) << endl;
}


/*
name: selectionSort
purpose: calls the private selectionSort function passing in head & finds the new head & tail
*/
template <typename T>
void List<T>::selectionSort() {
    //sets head equal to the new head returned by selectionSort
    head = selectionSort(head);

    //sets currNode equal to head
    listNode* currNode = head;

    //using currNode traverses to the end of the list to find the new tail
    while(currNode->nextNode != NULL) {
        currNode = currNode->nextNode;
    }

    //sets tail equal to the currNode
    tail = currNode;
}


#endif