/*
	CSC 1310 Program 4 - Markov Chains
	Sebjin Kennedy and G Harrison Simpson
	markovList.h
	Included in driver.cpp, holds class for the Markov List.
*/
#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

class markovList
{
	private:
		struct edge {
			string value; //value that the edge will go to
			edge* nextInList; //next value in linked list
			float weight; //likelihood this will be selected
			edge(string val, float wordWeight) //Edge constructor
			{
				weight = wordWeight;
				value = val;
				nextInList = NULL;
			}
		};
		int corpusSize;
		
		map<string, edge*> corpus; //map[key] = value
	public:
		markovList(const char*);
		~markovList();
		
		string generate(int);
};

markovList::markovList(const char* filename)
{
	
	ifstream file(filename);
	stringstream parser, splitter;//stream means that we are inputting using >> or <<; parser is key; splitter is value; map(key) = value;
	string line, index, word; 
	float weight;
	edge * newEdge;
	edge * tmp; //tmp holds the previous node to the node being added so that its next can be changed
	srand (time(0));
	
	if(file.good()) 
	{
		//Read in size and dynamically allocate array
		file >> corpusSize;
		file.ignore(1, '\n');

		//Outer while loop grabs vertices
		while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
		{
			parser.clear();
			parser << line;
			getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
			 //create new vertex and assign its value
			//Inner while loop grabs edge nodes
			while(getline(parser, word, ','))
			{
				//allocate a new node in the edge list
				splitter.clear();
				splitter.str(word);
				splitter >> word >> weight;
				//stick word and weight on the node you've just allocatezd---
				newEdge = new edge(word, weight);
				
				//make sure your new node is attached to the list---
				if (!corpus[index]) //If no edges exist yet, then this is the first edge
				{
					corpus[index] = newEdge;
				}
				else //if edge or edges already exist, make this new edge the last edge in the list
				{
					tmp = corpus[index];
					while (tmp->nextInList)
					{
						tmp = tmp->nextInList;
					}
					tmp->nextInList = newEdge;
				}
			}	
		}
	} 
	else {
		cout << "\nFile opening failed. Please check that desired file exists.";
	}
}

markovList::~markovList()
{
	for (map<string, edge*>::iterator iterator = corpus.begin(); iterator != corpus.end(); ++iterator) //used the au
	{
		edge * tmp = iterator->second;
		edge * next;
		while (tmp)
		{
			next = tmp->nextInList;
			delete next;
			tmp = next;
		}
	}
}
/*corpus.matrixArray = new matrix*[corpusSize]; 
		for (int i = 0; i < corpusSize; i++)
		{
			for (int j = 0; j < corpusSize; j++)
			{
				corpus.matrixArray[i][j] = 0;
			}
		}*/
string markovList::generate(int totalWordsOutputted)
{
	//map<int, float>::w/e we want = map[string] = edge;
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it, rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
	//write the rest of this
	//made a temporary iterator that would advance until it hit destination
	edge * tmpNode; //exists to basically make sure we are NOT affecting the actual list  shifting every part of the list one over
	float checkWeight; // checks the weight against desitnation weight
    float destinationWeightRandom;// this is the final weight we want to reach    
    string current = it->first;
	string jumbleOfWords = current;//this will be the final jumble of wordds that will have crap added on to it from the corpus 

    for (int i = 0; i < totalWordsOutputted; i++) //for loop to run through 100 words
    {
        destinationWeightRandom = (float)rand() / RAND_MAX; // pick a random number using a float finding the maximum random number
        tmpNode = corpus[current]; // set tmp node equal to current word that iterator picked
		checkWeight = tmpNode->weight;
		//Checks the weight
        while (tmpNode != NULL && checkWeight < destinationWeightRandom) // check if corpus is empty and if destination greater than check
        {
            //deincrement randnum by the amount of tmpNode->weight
			checkWeight = tmpNode->weight;
            destinationWeightRandom = destinationWeightRandom - checkWeight; // subtract tmpNode's weight from checkWeight
            tmpNode = tmpNode->nextInList; // iterate through list
        }
		//makes sure the tmpNode exits
        if (!tmpNode) // if there is no node
        {
            it = corpus.begin(); //reset current
            advance(it, rand () % corpusSize);
            current = it->first;
        }
		// gets the weight
        else
        {
            current = tmpNode->value; //reset current
            jumbleOfWords += " " + current;
        }
    }
    return jumbleOfWords;
}


#endif