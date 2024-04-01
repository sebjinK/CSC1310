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

        Node* mergeSort(Node * beg, Node * end) 
        {   //mergesort manages 
            print();
            Node * middle;
            Node * returnVal;
            //base case
            if (beg == NULL || beg->next == NULL)
            {
                return beg;
            }
            cout << "In if";
            middle = Split(beg,end);
            beg = mergeSort(beg, middle->previous);
            middle = mergeSort(middle, end);

            return merge(beg, middle);
        }

        Node * merge (Node * i, Node * j)
        {
            //assuming this is base case?
            if (i == NULL || j == NULL) {
                if (i)
                    return i;
                else 
                    return j;
            }
            if (&(i->value) > &(j->value)) 
            {
                i->next = merge(i->next, j);//assuming they pass the second partition too 
                i->next->previous = i;
                i->previous = NULL;
                return i;
            }
            else if (&(i->value) < &(j->value))
            {
                j->next = merge(i, j->next);
                j->next->previous = j;
                j->previous = NULL;
                return j;
            }
        }

        void print(Node ptr){
            int index = 0;
            cout << "DEBUG: Private print function called.\nRESULT:";
            while(ptr != NULL) {
                cout << endl << ++index << ptr->value;
                ptr = ptr->next;
            }
        }

        Node * Split(Node * beg, Node * end){
            while(beg != end && end->next != beg)
            {
                beg = beg->next;
                end = end->previous;
            }
            end->next = NULL;
            return beg;
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
                cout << ++index << ": " << *(i->value) << endl;
                i = i->next;
            }
            cout << "\nControl has successfully reached end of list. Goodbye!";
        }

        //Appends a new node to the linked list
        void append(T data) {
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
            cout << "\n" << *(newNode->value);
            cout << "\n" << *(head->value);
            cout << "\n" << *(tail->value);
            cout << endl;
        }
        //Public overload that sorts the data in descending order via merge sort
        void mergeSort() 
        {
            mergeSort(head, tail);
        }

        //Sorts the list in ASCENDING order via selection sort
};
#endif