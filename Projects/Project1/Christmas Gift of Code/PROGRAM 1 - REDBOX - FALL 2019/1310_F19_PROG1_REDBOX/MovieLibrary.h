/*
	Title:  MovieLibrary.h
	Author:  April R Crockett
	Date:  8/25/2019
	Purpose:  Be able to load from file, create, print, save & delete a movie library
*/
#ifndef MOVIELIBRARY_H
#define MOVIELIBRARY_H

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class MovieLibrary
{
	private:
		Movie** moviesArray; //an array of pointers - each pointer points to a single Movie
		int maxMovies; //maximum number of elements in the array
		int numMovies; //current number of movies in the array
		
		/*
			Function name:  resizeMovieArray (not part of the public interface)
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function is called by addMovieToArray when the array size is not big enough
							to hold a new movie that needs to be added.  The function makes the array twice
							as big as it currently is and then moves all the movie pointers to this new array.
		*/
		void resizeMovieArray();
		
	public:
		/*
			Function name:  MovieLibrary constructor 
			Parameters:  	An integer containing the maximum size of the movie library 
			Purpose:  		This function is automatically called when a Movies object is created and it creates a library
							of movies.  The function will dynamically allocate a movies array based
							on the maximum size and will also set the current number of movies to zero.
		*/
		MovieLibrary(int);
		/*
			Function name:  ~MovieLibrary destructor 
			Purpose:  		This function is automatically called when the Movies object is destroyed.
							This releases the dynamically created individual movies and then deletes the array.
		*/
		~MovieLibrary();
		/*
			Function name:  addMovieToArray 
			Parameters:  	none
			Returns: 		A boolean indicating if the movie was able to be added or not
			Purpose:  		This function should be called when you need to add a single movie to the
							movie library.
		*/
		void addMovieToArray();  
		/*
			Function name:  displayMovies 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to have all the movies
							in the library printed to the screen.
		*/
		void displayMovies();
		/*
			Function name:  displayMovieTitles 
			Parameters:  	none 
			Returns: 		none (void)
			Purpose:  		This function should be called when you want to print only the movie titles
							out of the movie library
		*/
		void displayMovieTitles();	
		/*
			Function name:  loadMoviesFromFile 
			Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to read movie data from a file
							and add the movies to the movie library.  The file must have data in the following order:
							title, length, year, genre, rating, number of Oscars won, star rating
		*/
		void loadMoviesFromFile(char* filename);		
		/*
			Function name:  removeMovieFromArray 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to remove one single movie
							from the movie library.  The movie to be removed must is identified
							by the user and then removed.
		*/
		void removeMovieFromArray();		
		/*
			Function name:  editMovieInArray 
			Parameters:  	none
			Returns: 		none
			Purpose:  		This function should be called when you need to edit a movie in the array
		*/
		//void editMovieInArray();	
		/*
			Function name:  saveToFile 
			Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to print all the movie data
							from the movie library to a file.  The data is printed in the following order (one piece
							of data per line):
							title, length, year, genre, rating, num oscars won, star rating
		*/
		void saveToFile(char *filename);		
		//accessor functions to get the attribute values
		//int getNumMovies() const;
		//int getMaxMovies() const;
		//Movie** getMoviesArray() const;
		//Movie* getAMovieFromArray(int index) const;
		
	
};



#endif