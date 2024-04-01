#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;


class List
{
    private:
        struct ListNode
            {
                string listString; //holds an 
                ListNode * next;   // holds a value of 
            };
        ListNode * head; //head and tail of List pointers
        ListNode * tail;
    public:
        void appendNode(string);
        /*
        o	appendNode function
            - 	accept a string as a parameter
            -	dynamically allocate a new ListNode and 
                set the ListNode’s value to the string sent to this function
            -	place the new node at the end of the linked list 
                (use the tail pointer to help!)
        */
        void insertNode(string);
        /*
        o	insertNode function
            -	accept a string as a parameter
            -	dynamically allocate a new ListNode and set the ListNode’s 
                value to the string sent to this function
            -	place the new node in the linked list alphabetically
                based on the string values.
        */
        void deleteNode(string);
        /*
        o	deleteNode function
            -	accept a string as a parameter
            -	traverse the linked list to search for 
                a node with the same value and delete it when found
        */
        void displayList() const;
        /*
        o	displayList function
	        -   display each node’s value in order from head to tail
        */
        List();
        /*
        o	Constructor
            -	Initialize head & tail to NULL
        */
        ~List();
        /*
        o	Destructor
            -	Delete all nodes that remain in the linked list
        */
};




#endif