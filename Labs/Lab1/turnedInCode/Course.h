/*
	Driver for Course Structure
	LAB 1 - CSC1310
	Name: Sebjin Kennedy
	Date: 1/25/2023
*/
#ifndef COURSE_H
#define COURSE_H


#include <iostream>

using namespace std;


struct Course
{
    string Name;
    string Location;
    string* sections;
    int numOfSections;
    int numCreditHours;
};

Course* createCourse(string, string, int, int); //returns a zpointer to the course variable 
                        /*
                        string containing name of the course
                        string containing location of the course
                        an integet containing how many secotions the course has
                        an integet containing how many credit hours the course has
                        */

void destroyCourse(Course*); //functions that will delete the the course array--will need to work on the for loop for the double pointer we're using

void printCourse(Course*); //function that will print out the possible 


#endif

