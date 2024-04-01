#ifndef HashTable_H
#define HashTable_H
#include <iostream>
#include <iomanip>
#include "HashEntry.h"
#include "Costume.h"
using namespace std;

class HashTable{
    private:
        
        int tableSize;
        HashEntry** hashArray; 

    public:
        HashTable(int size){
            tableSize = size;
            hashArray = new HashEntry*[tableSize];
			for(int i=0; i<tableSize; i++)
			{
				hashArray[i] = NULL;
			}
        }
        ~HashTable(){
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
					delete hashArray[i];
			}
			delete [] hashArray;
		}

        void putValue(int key, Costume* value){
			
			HashEntry* h = new HashEntry(key,value);
			
			
			//compute bucket index
			int bucketIndex = key % tableSize;
			
			cout << "BUCKET " << bucketIndex << endl;
			

			while(hashArray[bucketIndex] && hashArray[bucketIndex]->getKey() != key)
			{
				bucketIndex = (bucketIndex+1) % tableSize;
				cout << "BUCKET " << bucketIndex << endl;
			}
			
			//assign the new hash entry to the bucket index	
			hashArray[bucketIndex] = h;
		}
        void printHashTable()
		{
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
					cout << "|" << setw(8) << *(hashArray[i]->getValue()) << "|\n";
				else
					cout << "|" << setw(8) << -1 << "|\n";
			}
			cout << "----------\n\n";
		}
        

};

#endif