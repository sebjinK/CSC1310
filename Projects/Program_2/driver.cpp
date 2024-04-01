#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include "County.h"
#include "County.cpp"
#include "List.h"
//include your list header here------------------------------------------------------------------------

using namespace std;

int main()
{
	ifstream file;
	stringstream temp;
	string line, county, state;
	int index, pop;
	//file.open("counties_list.csv", ios::in);
	file.open("counties_ten.csv", ios::in);

	//create a new list of county pointers ------------------------------------------------------------------
	List<County*> List;
	County * newCounty;

	if(file.good()) {
	while(getline(file, line, ','))
	{
		temp.clear();
		temp.str(line);
		temp >> index;

		getline(file, line, ',');
		county = line;

		getline(file, line, ',');
		state = line;

		getline(file, line, '\n');
		temp.clear();
		temp.str(line);
		temp >> pop;

		newCounty = new County(index, county, state, pop);
		//append newCounty to your list-----------------------------------------------------------------------------------
		List.append(newCounty);
	}}

	file.close();
	cout << "Choose a sorting algorithm (1 - MergeSort, 2 - SelectionSort): ";
	int input;
	cin >> input;
	cout << endl;
	switch (input){
		case 1:
			List.print();
			List.mergesort();
			List.print();
			break;
		case 2:
			List.selectionSort();
			List.print();
			break;
	}

	return 0;
}