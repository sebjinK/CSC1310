/*
    Name:           List.h
    Authors:        Gaithel Simpson, Sebjin Kennedy
    Date:           3/5/2023
    Purpose:        holds classes and functions for list
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

        //MERGE SORT HELP: Sorts the data in descending order via merge sort
        Node* mergeSort(Node * beg, Node * end) {//mergesort manages 

            Node * middle;
            typename List<T>::listNode * returnVal;
            //base case
            if (beg->next == NULL)
            {
                return beg;
            }

            if (beg != NULL && end != NULL) //
            {
                middle = Split(beg,end);
                beg = mergeSort(beg, middle->previous);
                middle = mergeSort(middle, end);
            }
            //FIXME: IMPLEMENT MERGE HERE
            returnVal = merge(beg, middle);

            return returnVal; //FIXME
        }

        Node * merge (typename List<T>::Node * i, typename List<T>::Node * j)
        {
            //assuming this is base case?
            if (i == NULL || j == NULL) {
                if (i != NULL)
                    return i;
                else 
                    return j;
            }
            if (i->value > j->value) 
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

        void print(ptr){
            int index = 0;
            cout << "DEBUG: Private print function called.\nRESULT:";
            while(ptr != NULL) {
                cout << endl << ++index << ptr->value;
                ptr = ptr->next;
            }
        }

        Node * Split(typename List<T>::listNode * beg, typename List<T>::listNode * end){
            Node * lpos = beg;
            Node * rpos = end;
            while(lpos != rpos && rpos->next != lpos)
            {
                lpos = lpos->next;
                rpos = rpos->previous;
            }
            rpos->next = NULL;
            return lpos;
        }

        void swap(Node * indexNode, Node * swapNode)
        {
            Node * temp = indexNode;

            if (indexNode->next != swapNode)
            {
                indexNode = swapNode;
                swapNode = temp;
            }
            else
            {
                indexNode = swapNode;
                swapNode = temp;
            }
        }
    
    public:
        //Constructor function
        linkedList() {
            head = NULL;
            tail = NULL;
        }

        //Destructor function
        ~linkedList() {
            Node * i = head;
            Node * DELETEME;
            while(i != NULL) {
                DELETEME = i;
                i = i->next;
                delete DELETEME;
            }
        }

        //Prints entire linked list
        void print() {
            cout << "\n\n\nPROGRAM 2: SEBJIN KENNEDY AND G HARRISON SIMPSON" << endl;
            Node * i = head;
            int index = 0;
            while(i != NULL) {
                cout << endl;
                cout << ++index << ": " << *(i->value);
                i = i->next;
            }
            cout << "\nControl has successfully reached end of list. Goodbye!";
        }

        //Appends a new node to the linked list
        void append(T data) {
            //Create node and fill in data
            Node * newNode = new Node;
            newNode->value = data;
            newNode->next = NULL;

            //Filling in previous node and appending item to list
            if(tail == NULL) {
                head = newNode;
                newNode->previous = NULL;
            } else {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
        }
        
        //Public overload that sorts the data in descending order via merge sort
        void mergeSort() {
            mergeSort(head, tail);
        }

        //Sorts the list in ASCENDING order via selection sort
        
        void SelectionSort()
        {
            Node * nodeTraveler;
            Node * nodeSwap;
            //first loop will traverse nodeTraveler
            for (nodeTraveler = head; nodeTraveler != tail; nodeTraveler = nodeTraveler->next)
            {
                cout << "\n\n" << nodeTraveler->value << endl;

                for (Node * i = nodeTraveler->next; i != tail; i = i->next)
                {
                    if (*(nodeTraveler->value) > *(nodeSwap->value))
                    {
                        nodeSwap = i;
                    }
                }
                swap(nodeTraveler, nodeSwap);
            }
            

        }
};
#endif