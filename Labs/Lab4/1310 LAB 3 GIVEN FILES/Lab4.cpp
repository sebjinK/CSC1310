/*****************************************************************
	Title:  		Lab4.cpp
	Creation Date:  9-26-2019
	Last Updated:	1-31-2021
	Author: 		April Crockett edited by Sebjin kennedy
	Purpose:		CSC 1310 Lab 4
******************************************************************/

#include <iostream>
#include <cstring>
#include "List.h"
using namespace std;

int main()
{
	// Define a LinkedList object.
	List halloweenList;
	
	// Append (add to the end) values to the list
	cout << "\n\nI am appending several strings to the list.\n\n";
	halloweenList.appendNode("boogeyman");
	halloweenList.appendNode("ghost");
	halloweenList.appendNode("scarecrow");
	halloweenList.appendNode("witch");
	halloweenList.appendNode("zombie");
	
	halloweenList.displayList();
	
	//Insert
	cout << "\n\nI am inserting vampire in the list.\n\n";
	halloweenList.insertNode("vampire");
	
	halloweenList.displayList();
	
	
	//Delete
	cout << "\n\nI am deleting ghost from the list.\n\n";
	halloweenList.deleteNode("ghost");
	
	halloweenList.displayList();

	return 0;
}

List::List()
{
	head = NULL;
	tail = NULL;
}
List::~List()
{
	ListNode * nodeTraverser; 	//traverses the list
	ListNode * nextNode;

	//node pointer is positioned at the head of the list
	nodeTraverser = head;

	//while loop that runs as long as nodePtr isn't NULL (or at the end of the list)
	while (!nodeTraverser)
	{
		nextNode = nodeTraverser->next; //make a temporary save for the next pointer
		delete nodeTraverser;
		nodeTraverser = nextNode;
	}
}
void List::appendNode(string passedStr)
{
	ListNode * newNode;

	newNode = new ListNode; //dynamically allocate a new node and store string there
	newNode->listString = passedStr;
	newNode->next = NULL;

	if (!head)
	{
		head = newNode; //since there are no nodes in the list yet, 
		tail = newNode; //make newNode the first node
	}
	else
	{
		tail->next = newNode; //
		tail = newNode;
	}


}
void List::deleteNode(string passedStr)
{
	ListNode *nodeTraverser;
	ListNode *prevNode;
	
	if (!head)
		return;

	if(head->listString == passedStr)
	{
		nodeTraverser = head->next;
		delete head;
		head = nodeTraverser;
	}	
	else
	{
		nodeTraverser = head;

		while (nodeTraverser && nodeTraverser->listString != passedStr)
		{
			prevNode = nodeTraverser;
			nodeTraverser = nodeTraverser->next;
		}

		if (nodeTraverser)
		{
			if (nodeTraverser == nodeTraverser)
			{
				tail = prevNode;
			}
			prevNode->next = nodeTraverser->next;
			delete nodeTraverser;
		}

	}
}
void List::insertNode(string passedStr)
{
	ListNode * nodeTraverser;
	ListNode * newNode;
	ListNode * tempNode; //makes a temp memory for node Traverser

	newNode = new ListNode; //allocate a new node within new node
	newNode->listString = passedStr; // pass string into newnode

	if (!head) //checks to see if string is empty
	{                                                                                                                                                                                                                                                                                                                                               
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodeTraverser = head;//start from beginning of the list
		if (newNode->listString < nodeTraverser->listString) //check if new node is alphabetically lower than nodetraverser
		{
			newNode->next = head; //make the data in new node the new head
			head = newNode;
		}
		while (nodeTraverser != tail) //node traverser isn't at the tail yet so this while loop will iterate
		{
			if (newNode->listString < nodeTraverser->listString) //does the same check as last time
			{
				nodeTraverser = tempNode; //save nodetraverser as a temporary node
				break;
			}
			else
			{
				tempNode = nodeTraverser;//save node traverser within tempnode
				nodeTraverser = nodeTraverser->next;//node traverser moves to next node
			}
		}

		if (nodeTraverser->next == NULL)
		{
			tail = newNode; //save the tail
		}
		newNode->next = nodeTraverser->next; //save node traverser
		nodeTraverser->next = newNode; //set nodetraverser to one before the node
	}
}
void List::displayList() const
{
	ListNode * nodeTraverser;

	if (head != NULL)
	{
		nodeTraverser = head;

		while (nodeTraverser)
		{
			cout << nodeTraverser->listString << endl;

			nodeTraverser = nodeTraverser->next;
		}
	}
	else
		cout << "\nThere are no nodes inthe list. \n";
}
