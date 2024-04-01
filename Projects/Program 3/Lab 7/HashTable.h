/*
Name:                   HashTable.h
Author:                 Sebjin Kennedy
Date:                   3/22/2023
Purpose:                Implements the hash table class
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <iomanip>
#include "HashEntry.h"

using namespace std;


class HashTable
{ 
    private:
        HashEntry ** singleHashArray;
        int tableSize;
    public:
        HashTable(int);
        ~HashTable();
        Costume * getValue(int);
        void putValue(int, Costume*);
        void printHashTable();
};
/////////////////////////////////////////////////////////////////////
///////////////////////////CONSTRUCTOR///////////////////////////////
HashTable::HashTable(int size)
{
    tableSize = size;
    singleHashArray = new HashEntry*[tableSize]; //dynamically sets up a poitner
    for (int i = 0; i < tableSize; i++)
    {
        singleHashArray[i] = NULL;
    }

}
/////////////////////////////////////////////////////////////////////
//////////////////////////DESTRUCTOR/////////////////////////////////
HashTable::~HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        if (singleHashArray[i] != NULL)
            delete singleHashArray[i];
    }
    delete [] singleHashArray;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////GET VALUE///////////////////////////////////
Costume * HashTable::getValue(int key)
{
    int bucketIndex = key % tableSize;
    while (singleHashArray[bucketIndex]!= NULL && singleHashArray[bucketIndex]->getKey() != key)
    {
        bucketIndex = (bucketIndex + 1) % tableSize;
    }
    if (singleHashArray[bucketIndex] == NULL)
        return nullptr;
    else
        return singleHashArray[bucketIndex]->getValue();
}
/////////////////////////////////////////////////////////////////////
/////////////////////////PUT VALUE//////////////////////////////////
void HashTable::putValue(int key, Costume * value)
{
    HashEntry * h = new HashEntry(key, value);
    int bucketIndex = key % tableSize;
    cout << "BUCKET " << bucketIndex << endl;

    while (singleHashArray[bucketIndex]!= NULL && singleHashArray[bucketIndex]->getKey() != key)
    {
        bucketIndex = (bucketIndex + 1) % tableSize;
        cout << "BUCKET " << bucketIndex << endl;
    }

    singleHashArray[bucketIndex] = h;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////PRINT HASH TABLE////////////////////////////
void HashTable::printHashTable()
{
    cout << "---------\n";

    for (int i = 0; i < tableSize; i++)
    {
        if (singleHashArray[i] != NULL)
            cout << i + 1 << setw(8) << *(singleHashArray[i]->getValue()) << "|\n";
        else
            cout << "|" << setw(8) << -1 << "|\n";
    }
    cout << "---------\n";
}

#endif