/*
Name:			Lab2.cpp
Author:			Sebjin Kennedy
Date: 			2/8/2022
Required Files:	Lab2Driver.cpp	Timer.cpp	Timer.h
Purpose:		See which sorting algorithims are the quickest
*/
#include "Timer.h"
#include "Timer.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords); //swap two numbers using a temp variable
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);


	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
		cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
		
		for(int x = 0; x < numWords; x++)
		{
			outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
		}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	
	outfile.open("sortFileReverseBubble.txt");
		cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
		for(int x=0; x<numWords; x++)
		{
			outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
		}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quicksort(wordArray, 0, numWords - 1);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
		for(int x=0; x<numWords; x++)
		{
			outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
		}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(wordCount *wordArray, int numWords)
{
	string tempWord;
	int tempCount;
	bool swapped;

	for (int i = 1; i < numWords; i++)
	{
		tempWord = wordArray[i].word;
		tempCount = wordArray[i].count;//set the temp variables equal to index i

		int j = i - 1; // set index j to 1 less than the for loop

		while (j >= 0 && wordArray[j].count > tempCount)
		{
			wordArray[j + 1].word = wordArray[j].word;
			wordArray[j + 1].count = wordArray[j].count;
			j--;
		}
		wordArray[j + 1].word = tempWord;
		wordArray[j + 1].count = tempCount;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubbleSortReverse(wordCount * wordArray, int numWords)
{
	for (int i = 0; i < numWords; i++) // checks each element one
	{
		for (int j = 0; j < numWords - i - 1; j++) //
		{
			if (wordArray[j].count < wordArray[j + 1].count)
			{
				int tempCount;
				string tempWord;

				tempCount = wordArray[j].count;
				tempWord = wordArray[j].word;

				wordArray[j].count = wordArray[j + 1].count;
				wordArray[j].word = wordArray[j + 1].word;

				wordArray[j + 1].count = tempCount;
				wordArray[j + 1].word = tempWord;
			}
		}
	}
}

//LOOK!  WRITE YOUR PARTITION FUNCTION HERE

int partition(wordCount * wordArray, int left, int right)
{
	int pivotCount = 0;


	pivotCount = wordArray[left].count;
	int l = left - 1;
	int r = right + 1;

	while (l < r)
	{
		do
		{
			r--;
		} while (wordArray[r].count > pivotCount);
		do
		{
			l++;
		} while (wordArray[l].count < pivotCount);
		if (l < r)
		{
			swap(wordArray[l].count, wordArray[r].count);
			swap(wordArray[l].word, wordArray[r].word);
		}
		
	}
	return r; //FIXME
}

//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quicksort(wordCount * wordArray, int low, int high)
{
	int pivot = 0;

	if (low >= high)
	{
		return;
	}

	pivot = partition(wordArray, low, high);
	quicksort(wordArray, low, pivot);
	quicksort(wordArray, pivot + 1, high);
}
