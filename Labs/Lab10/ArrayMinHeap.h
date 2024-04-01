#ifndef ARRAYMINHEAP_H
#define ARRAYMINHEAP_H
#include "Creature.h"
#include <iostream>
#include <cmath>


using namespace std;


class ArrayMinHeap
{
    private:
        Creature * heapArray;
        int capacity;
        int heap_size;
        void swap(int i1, int i2)
        {
            Creature temp = heapArray[i1]; // holder var holds first index, swap the two indexes, make the second index equal to the first
            heapArray[i1] = heapArray[i2];
            heapArray[i2] = temp;
        }
        
        int parent(int i) // helper function that holds the index for parent
        {
            return (i - 1) / 2;
        }
        
        int left(int i) // helper function that holds the index for left child
        {
            return (i * 2) + 1;
        }
        
        int right(int i) // helper function that holds the index for right child
        {
            return (i * 2) + 2;
        }

    public:
        ArrayMinHeap(int maxCap) //default constructor
        {
            capacity = maxCap;
            heapArray = new Creature[maxCap]; // dynamic allocation for the heapArray
            heap_size = 0;
        }
        
        ~ArrayMinHeap()
        {
            delete [] heapArray; // simple delete for a single array heap
        }
        
        void minHeapify(int index)
        {
            int parentIndex = index;

            int rightChildIndex = right(index); // hold left and right index
            int leftChildIndex = left(index);

            //check if heap size is bigger than left/right child and check if name of parent is > left/right child
            if (heap_size > leftChildIndex && heapArray[index].getName() > heapArray[leftChildIndex].getName())
                parentIndex = rightChildIndex; // move the parent to right
            if (heap_size > rightChildIndex && heapArray[parentIndex].getName() > heapArray[rightChildIndex].getName())
                parentIndex = leftChildIndex; // move the parent to left`
            // if if they do change then swap the parent and recursively  heapify the index
            if (parentIndex != index)
            {
                swap(index, parentIndex);
                minHeapify(parentIndex);
            }
        }
        

        Creature peek() // check the root
        {
            if (isEmpty())
                return heapArray[0]; //root is alredy empty
            else
                return heapArray[0];
        }
        
        bool remove()
        {
            //SWAP THE FIRST AND LAST 
            if (heap_size == 0) // check if empty 
            {
                cout << "\nEmpty";
                return false;
            }
            else if (heap_size == 1) // chcek if its only the root
            {
                heap_size--;
                return false;
            }
            Creature root = heapArray[0];
            heapArray[0] = heapArray[heap_size - 1];
           // heapArray[heap_size - 1] = root;
            heap_size--;
            minHeapify(0);
            return true;
        }`
        
        void insert(Creature newValue)
        {
            if (heap_size == capacity) //call resize to increase heap_size
                resizeArray();
            else
            { // fill in the array element with new vlue and increase heap_size
                heapArray[heap_size] = newValue;
                heap_size++;
                int i = heap_size - 1;

                while (i > 0 && heapArray[parent(i)].getName() > heapArray[i].getName())
                {
                    swap(i, parent(i)); // set the newValue in its rgiht place in the heap
                    i = parent(i);
                }
            }
        }
        
        void resizeArray()
        {
            int cap = capacity * 2; // increase capacity size
            Creature * tempArray = new Creature[cap];

            for (int i = 0; i < capacity; i++)
                tempArray[i] = heapArray[i];
            delete [] heapArray;
            heapArray = tempArray; // rebuild heaparray with temp array
            capacity = cap;
        }   
        
        bool isEmpty()
        {
            if (heap_size == 0) // just check if empty
                return true;
            else   
                return false;
        }
        
        int getNumberOfNodes()
        {
            return heap_size;
        }
        
        int getHeight()
        {
            return ceil(log2(heap_size + 1)); // ceiling of log base 2 of heap size + 1
        }
        
        void display()
        {
            if(isEmpty()) 
                cout << "\nERROR: Heap's empty!";
            else 
            {
                cout << endl;
                for(int i = 0; i < heap_size; i++) 
                    cout << endl << heapArray[i].getName(); // iterate through the array
            }
        }
        
        void saveToFile()
        {
             //iterate through heap and save each node
            for (int index = 0; index < heap_size; ++index)
            {
                heapArray[index].printCreatureToFile("savedCreatures.txt");
                index++;
            }
        }
};
#endif