/*
	CSC 1310 Program 4 - Markov Chains
	Sebjin Kennedy and G Harrison Simpson
	driver.cpp
	Creates a Markov chain with the help of markovList.h.
*/

#include <iostream>
//#include "markovMat.h"
#include "markovList.h"
using namespace std;

int main() {
	markovList* chain = new markovList("corpusTest.txt");
	//markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}