/*
Name:               program1.cpp
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            Store, load, add, remove, display any loaded video games from text files. 
                    Can also remove video game from file
*/
#include "text.h"
#include "text.cpp"
#include "videogame.h"
#include "videogame.cpp"
#include "videogamelibrary.h"
#include "videogamelibrary.cpp"

int main()
{
    int choice;
    int numLibrarySize;

    cout << "How many games can your library hold? ";
    cin >> numLibrarySize;
    while (numLibrarySize <= 0)
    {
        cout << "\nPlease enter a number greater than 0\n";
        cin >> numLibrarySize;
    }

    cout << "What would you like to do?\n";
    cout << "1.\tLoad video games from file\n";
    cout << "2.\tSave video games to a file\n";
    cout << "3.\tAdd a video game\n";
    cout << "4.\tRemove a video game\n";
    cout << "5.\tDisplay all video games\n";
    cout << "6.\tRemove ALL video games from this library and end program.\n";
    cout << "CHOOSE 1-6: ";


    while (choice <= 0 || choice >= 7)
    {
        cout << "Please choose between 1 through 6" << endl;
        cout << "CHOOSE 1-6: ";
        cin >> choice;
    }

    switch (choice)
    {
        case 1:
            /*load games*/
            break;
        case 2:
            /*save games*/
            break;
        case 3:
            /*Add games*/
            break;
        case 4:
            /*Remove games*/
            break;
        case 5:
            /*Display all games*/
            break;
        case 6:
            /*Remove all games*/
            break;
    }
    cout << "GOODBYE" << endl;
    return 0;
}