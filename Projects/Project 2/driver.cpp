#include<fstream>
#include<iostream>
#include<string>
#include<sstream>//you can share a terminal apparently
//go to exetension, it should say "share terminal"
#include "County.h"
//include your list header here------------------------------------------------------------------------
#include "List.h"
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
	linkedList<County*> List;

	County* newCounty;

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
	}}

	file.close();

	//call mergesort---------------------------------------------------------------------------------------------
	cout << "\nSorting: pls wait\n";
	List.mergeSort();
	cout << "\nSorted! nice job dumbass :D\n";
	//print the list-----------------------------------------------------------------------------------------------------

	return 0;
}