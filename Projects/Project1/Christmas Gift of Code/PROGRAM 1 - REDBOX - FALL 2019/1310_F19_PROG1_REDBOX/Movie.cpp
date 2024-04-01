/*
	Title:  Movie.cpp
	Author:  April Crockett
	Date:  8/26/2019
	Purpose:  Be able to create, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"
#include "Text.cpp"

Movie::Movie(Text* title, int year, Text* genre, Text* rating, float stars) //all info is know
{
	//assign parameter data to structure members
	movieTitle = title;
	movieYear = year;
	movieGenre = genre;
	movieRating = rating;
	movieNumStars = stars;
}

Movie::~Movie()
{
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

void Movie::printMovieDetails()
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	movieTitle->displayText();
	cout << endl;
	cout << right << setw(30) << "Year Released:  " << left << movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	movieGenre->displayText();
	cout << endl;
	cout << right << setw(30) << "Rating:  " << right << setw(30);
	movieRating->displayText();
	cout << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << endl << endl;
}

void Movie::printMovieDetailsToFile(ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, movieTitle->getText(), 1000);
	outFile << temp << endl;
	outFile << movieYear << endl;
	strncpy(temp, movieGenre->getText(), 1000);
	outFile << temp << endl;
	strncpy(temp, movieRating->getText(), 1000);
	outFile << temp << endl;
	outFile << movieNumStars << endl;
}

Text* Movie::getMovieTitle() const
{
	return movieTitle;
}

