/*
	Driver for Course Structure
	LAB 1 - CSC1310
	Name: Sebjin Kennedy
	Date: 1/25/2023
*/

#include "Course.h"


Course* createCourse(string courseName, string courseLoc, int numSections, int numCR) //returns a pointer to the course variable 
{
    Course* coursePointer;

    coursePointer = new Course; //creates a second array that will hold the sections 

    coursePointer->Name = courseName;
    coursePointer->Location = courseLoc;
    coursePointer->numOfSections = numSections;
    coursePointer->numCreditHours = numCR;
    coursePointer->sections = new string[numSections];

    return coursePointer;
}

void destroyCourse(Course* myCourse) //functions that will delete the the course array--will need to work on the for loop for the double pointer we're using
{
    delete [] myCourse->sections;
    delete [] myCourse;
}

void printCourse(Course* myCourse) //function that will print out the possible 
{
    cout << "COURSE NAME:\t\t\t" << myCourse->Name << "\n\n";
    cout << "COURSE LOCATION:\t\t" << myCourse->Location << "\n\n";
    cout << "COURSE HOURS:\t\t\t" << myCourse->numCreditHours << "\n\n";
    cout << "COURSE SECTIONS:\t\t\n";
    for(int i = 0; i < myCourse->numOfSections; i++)
    {

        cout << "\t\t\t\t" << myCourse->sections[i] << "\n\n";
    }
}


