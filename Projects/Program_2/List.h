/*
    Author: Ethan Byker
    Purpose: Creation of A list and the Algorithm to Sort the List
    Date: 10/8/23  
*/




#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "County.h"
using namespace std;

template <typename T>
//Creation of List CLass
class List{
    private:
        //Creation of ListNode Structure making the foundation for my whole program
        struct ListNode
        {
            T data;
            ListNode* Next;
            ListNode* Previous;
        };
        ListNode* Head;
        ListNode* Tail;

        //Print Function simply prints the index of the assorted list for debugging
        void print(ListNode* Head){
            ListNode* tempPtr = new ListNode;
            tempPtr = Head;
            while(tempPtr != NULL){
                cout << *(tempPtr->data) << endl;
                tempPtr = tempPtr->Next;
            }

        }
        //Mergesort!!!- Splits the list into tiny partitions then rebuilds it in the correct order

        ListNode* mergesort(ListNode* first,ListNode* last){
            ListNode* Node1;
            ListNode* Node2;
           
            
            if((first == NULL) || (first->Next == NULL)){
                return first;
            }
                Node1 = first;
                Node2 = split(first,last);
                
                Node1 = mergesort(Node1,Node2->Previous);
                Node2 = mergesort(Node2, last);
                
                return merge(Node1,Node2);
            
        }
        //Merge Function to build it back together

        ListNode* merge(ListNode* Node1, ListNode* Node2){
        if(!Node1)
            return Node2;
        if(!Node2)
            return Node1;

        if(*(Node1->data) < *(Node2->data)){
            Node1->Next = merge(Node1->Next,Node2);
            Node1->Next->Previous = Node1;
            Node1->Previous = NULL;
            return Node1;
        } else {
            Node2->Next = merge(Node2->Next,Node1);
            Node2->Next->Previous = Node2;
            Node2->Previous = NULL;
            return Node2;
        } 
                

        }

        //Split Function to take it apart

         ListNode* split(ListNode* first,ListNode* last){
                ListNode* temp;
                while(first != last && first->Next != last){
                    first = first->Next;
                    last = last->Previous;

                }
                temp = first->Next;
                last->Next = NULL;
                return temp;
        }

    public:
        //List Constructor
        List(){
            Head = NULL;
            Tail = NULL;
        }
        //List Deconstructor to delete the list
        ~List(){

            ListNode* CurNode = Head;
            ListNode* sucNode;

            while(CurNode != NULL){
                
                sucNode = CurNode;
                CurNode = CurNode->Next;
                delete sucNode;
                
            }
        }
        //Calls the private print function
        void print(){
            this->print(Head);
        }

        //Appends data to the list
        void append(T newCounty){
            ListNode* NewNode = new ListNode;
            NewNode->data = newCounty;


            if(!Head){
                Head = NewNode;
                Tail = NewNode;
            } else {
                if(Head == Tail){
                    Head->Next = Tail;
                }
                Head->Previous = NULL;
                Tail->Next = NewNode;
                NewNode->Previous = Tail;
                Tail = NewNode;
                Tail->Next = NULL;
            }
        }
        //Calls Privaate mergesort function
        void mergesort(){
            Head = mergesort(Head,Tail);
            ListNode* temp = Head;
            
            while(temp->Next != NULL){
                temp = temp->Next;
            }
            Tail = temp;
        }
        //Selection Sort, Runs through the list to find a smaller number than the CurNode
        //then replaces it with that or itself untill it reaches the end of the list
        void selectionSort(){
            ListNode* CurNode = new ListNode;
            ListNode* SucNode;
            ListNode* smallest;;
            CurNode = Head;
            while(CurNode != NULL){
                smallest = CurNode;
                SucNode = CurNode;
                while(SucNode != NULL){
                    if(SucNode->data->getPopulation() < smallest->data->getPopulation())
                        smallest = SucNode;
                    SucNode = SucNode->Next;
                }
                swap(CurNode,smallest);
                CurNode = CurNode->Next;
            }
        }
        //Swap Function to switch the data between Nodes
        void swap(ListNode*& Node1, ListNode*& Node2){
            ListNode* Temp = new ListNode;
            Temp->Next = NULL;
            Temp->Previous = NULL;

            Temp->data = Node1->data;
            Node1->data = Node2->data;
            Node2->data = Temp->data;
        }
};

#endif