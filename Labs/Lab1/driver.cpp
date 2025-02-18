/*
	Driver for Course Structure
	LAB 1 - CSC1310
	Name: Sebjin Kennedy
	Date: 1/25/2023
*/

#include "Course.h"
#include "Course.cpp"
int main ()
{
	//WORKING on
	//Create a pointer to an array of Course pointers called myCourses here -
	Course **myCourses;

	
	int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	//WORKING on
	//Dynamically allocate a new array of pointers to Courses of size numCourses and assign this array to myCourses
	myCourses = new Course* [numCourses];
	
	for (int i = 0; i < numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);

		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		//WORKING ON
		//Call the createCourse function and make sure to assign the returned value to myCourses[i]
		myCourses[i] = createCourse(name, location, numHours, numSections);

		
		for (int j = 0; j < myCourses[i]->numOfSections; j++)
		{
			cout << "\nSECTION " << j + 1 << ":\t\t";
			//WORKING ON
			//Read in the string from the user and put in the correct array element of the sections array
			getline(cin, myCourses[i]->sections[j]);
		}
		cout << "\n*******************************\n";
	}
	
	cout << "\n\nThe following are the courses you entered:\n\n";
	for (int i = 0; i < numCourses; i++)
	{
		cout << "******************************* COURSE " << (i + 1) << "*******************************\n";
		printCourse(myCourses[i]);
	}
	
	for (int i = 0;  i < numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete [] myCourses;
	
	cout << endl << endl;
	return 0;
}