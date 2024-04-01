/*
Name:           DynStack.h
Author:         Sebjin Kennedy
Date:           March 5th, 2023
Purpose:        holds functions and class that will manipulate the inventory item's position in the stack
*/
#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>

using namespace std;

template<typename S>
class dynStack
{
private:
    struct StackNode
    {
        S value;
        StackNode * next;
    };
    StackNode * topStackNode;
public:
    dynStack() {topStackNode = NULL;}
    //constructor
    void pop(S &);
    void push(S);
    bool isEmpty();
};

//make a new node to push on the dynStack
template<typename S>
void dynStack<S>::push(S item)
{
    StackNode * newNode;
    newNode = new StackNode;
    newNode->value = item;

    if (isEmpty())
    {
        topStackNode = newNode; //makes next and value = new node
        newNode->next = NULL; //makes anything below next equal to 
    }
    else
    {
        newNode->next = topStackNode;
        topStackNode = newNode;
    }
}

template <typename S>
void dynStack<S>::pop(S& item)
{
    StackNode * tempNode = NULL;
    item = topStackNode->value;
    tempNode = topStackNode->next;
    delete topStackNode;
    topStackNode = tempNode; 
}

template <typename S>
bool dynStack<S>::isEmpty()
{
    bool status;
    
    if (!topStackNode)
        status = true;
    else
        status = false;

    return status;
}
#endif


