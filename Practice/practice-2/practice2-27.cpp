#include <iostream>


using namespace std;

int main()
{
    
}
//Lists
/*


*/
//Linked Lists
/*


*/


//how does the call stack work?
/*
    think: add and remove from the top of the stack
    Static Stacks - Arrays
    Dynamic Stacks - Linked Lists
*/

//Queues
/*
    like stacks limit access to data in a container

    Think: remove from front, add to back

    Functions:
    //Enqueue(dataType additionalData) -- add data to end of queue -- pass the index of the data packet you are trying to add 
    //Dequeue() -- remove data from front of queue --  pass nothing
    //Peak() - return front item of queue


    Static/Dynamic Queues:
    rear->next = newNode

    vs 

    rear = newNode

    if (rear == null)
    {
        rear->next  => SEGMENTATION FAULT
    }

    to traverse the list/queue, utilize a currentValue 


    curr->Value;
    curr->next;

    if you just have curr = ...; then it would hcange the node current is pointing to 

*/