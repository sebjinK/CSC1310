/*
	Title:  RedBox.cpp
	Author:  April Crockett
	Date:  11/7/2017
	Purpose:  To demonstrate the MovieLibrary, Movie, and Text object code working
	by allowing the user to add, save, delete, and load movies to/from a library.
*/

#include "MovieLibrary.h"
#include "Movie.h"
#include "Text.h"
#include "MovieLibrary.cpp"
#include <iostream>
using namespace std;

int main()
{
	int menuChoice;
	int maxMovies;
	char filename[25];
	
	cout << "\n\nHow many movies can this RedBox hold?\n";
	cin >> maxMovies;
	while(maxMovies <= 0)
	{
		cout << "\n\nYou have to have at least one movie available in RedBox.\n";
		cout << "How many movies can this RedBox hold?\n";
		cin >> maxMovies;
	}
	MovieLibrary* movieLibrary = new MovieLibrary(maxMovies);
	
	do
	{
		cout << "\n\nWhat would you like to do?\n";
		cout << "1.  Load movies from file.\n";
		cout << "2.  Save movies to a file.\n";
		cout << "3.  Add a movie.\n";
		cout << "4.  Remove a movie.\n";
		cout << "5.  Display all movies.\n";
		cout << "6.  Remove ALL movies from this RedBox and end program.\n";
		cout << "CHOOSE 1-6:  ";
		cin >> menuChoice;
		while(menuChoice < 1 || menuChoice > 6)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-6:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:	cout << "\n\nWhat is the name of the file? (example.txt):  ";
					cin >> filename;
					movieLibrary->loadMoviesFromFile(filename);
					break;
					
			case 2: cout << "\n\nWhat do you want to name the file? (example.txt):  ";
					cin >> filename;
					movieLibrary->saveToFile(filename); 
					break;
					
			case 3:	//add a movie
					movieLibrary->addMovieToArray();
					break;
					
			case 4:	//delete a movie if there is more than one movie in the library.
					movieLibrary->removeMovieFromArray();
					break;
					
			case 5: //print all movies
					movieLibrary->displayMovies();
					break;
					
			case 6: //delete all movies
					delete movieLibrary;
					break;
					
		}
		
	} while(menuChoice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	
	return 0;
}
