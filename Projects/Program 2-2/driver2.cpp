#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
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
	//linkedList<County*> List;

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
		//List.append(newCounty);
	}}

	file.close();
	cout << "Hello";
	//call mergesort---------------------------------------------------------------------------------------------
	//print the list-----------------------------------------------------------------------------------------------------

	return 0;
}