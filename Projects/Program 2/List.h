/*
    Name:           List.h
    Authors:        Gaithel Simpson, Sebjin Kennedy
    Date:           3/5/2023
    Purpose:        holds classes and functions for list
    /////A TA helped us complete the assignment (thanks Pooja!)\\\\\
*/
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;


template <typename T>
class linkedList
{
    private:
        struct Node //struct that holds the data for the individual nodes
        {
            T value; 
            Node * next;
            Node * previous;
        };
        Node * head; //doubly linked list
        Node * tail;
        //Uses split 
        Node* mergeSort(Node * beg, Node * end);
        Node * merge (Node *, Node *);
        void print(Node *ptr);

        Node * Split(Node * beg, Node * end);
        
    public:
        //Constructor function
        linkedList() {
            head = NULL;
            tail = NULL;
        }

        //Destructor function
        ~linkedList();

        //Prints entire linked list
        void print();

        //Appends a new node to the linked list
        void append(T data);
        
        //Public overload that sorts the data in descending order via merge sort
        void mergeSort();
        
        //FIXMESorts the list in ASCENDING order via selection sort
};
///////////////////////////PRIVATE MERGE SORT FUNCTION///////////////////
template<typename T>
typename linkedList<T>::Node* linkedList<T>::mergeSort(Node * beg, Node * end) {//mergesort manages 
    Node * middle;
    Node * returnVal;
    //base case
    if (beg == NULL || beg->next == NULL)
    {
        return beg;
    }
    middle = Split(beg,end);
    beg = mergeSort(beg, middle->previous);
    middle = mergeSort(middle, end);

    return merge(beg, middle);
}
//////////////////////////MERGE FUNCTION/////////////////////////
template <typename T>
typename linkedList<T>::Node * linkedList<T>::merge (Node * i, Node * j)
{
    //assuming this is base case?
    if (i == NULL)
        return j;
    if (j == NULL)
        return i;

    if (*(i->value) > *(j->value)) 
    {
        i->next = merge(i->next, j);//assuming they pass the second partition too 
        i->next->previous = i;
        i->previous = NULL;
        return i;
    }
    else
    {
        j->next = merge(i, j->next);
        j->next->previous = j;
        j->previous = NULL;
        return j;
    }
}
////////////////////////////PRIVATE PRINT FUNCITON//////////////////////
template <typename T>
void linkedList<T>::print(Node *ptr){
    int index = 0; 
    cout << "DEBUG: Private print function called.\nRESULT:";
    while(ptr != NULL) {
        cout << endl << ++index << ". " << *(ptr->value);
        ptr = ptr->next;
    }
    
}
////////////////////////SPLIT FUNCTION////////////////////////////
template<typename T>
typename linkedList<T>::Node * linkedList<T>::Split(Node * beg, Node * end){
    Node* temp;
    while(beg != end && beg->next != end)
    {
        beg = beg->next;
        end = end->previous;
    }
    temp = beg->next;
	beg->next = NULL;
	return temp;
}
/////////////////////////DESTRUCTOR FUNCTION///////////////////////
template<typename T>
linkedList<T>::~linkedList() {
    Node * i = head;
    Node * DELETEME;
    while(i) {
        DELETEME = i->next;
        delete i;
        i = DELETEME;
    }
}
/////////////////////////PUBLIC PRINT FUNCTION////////////////////
template<typename T>
void linkedList<T>::print() {
    cout << "\n\n\nPROGRAM 2: SEBJIN KENNEDY AND G HARRISON SIMPSON" << endl;
    print(head);
    cout << "\nControl has successfully reached end of list. Goodbye!";
}
///////////////////////APPEND FUNCITON//////////////////////
template<typename T>
void linkedList<T>::append(T data) {
    //Create node and fill in data
    Node * newNode = new Node;
    newNode->value = data;

    //Filling in previous node and appending item to list

    if(head == NULL) {
        head = newNode;
        tail = newNode;
    } 
    else {
        if (head == tail)
        {
            head->next = tail;
        }
        head->previous = NULL;
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        tail->next = NULL;
    }
}
/////////////////////PUBLIC MERGE SORT FUNCIOTN//////////////////
template<typename T>
 void linkedList<T>::mergeSort() 
{
    head = mergeSort(head, tail);
    Node * temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }
    tail = temp;
}
#endif