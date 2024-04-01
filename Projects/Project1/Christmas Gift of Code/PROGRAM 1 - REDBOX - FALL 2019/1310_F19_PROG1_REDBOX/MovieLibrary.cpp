/*
	Title:  MovieLibrary.cpp
	Author:  April R Crockett
	Date:  8/25/2019
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "MovieLibrary.h"
#include "Movie.h"
#include "Movie.cpp"

MovieLibrary::MovieLibrary(int max)
{
	maxMovies = max;
	numMovies = 0;
	
	//dynamically create the array that will hold the movies
	moviesArray = new Movie*[max];
}

MovieLibrary::~MovieLibrary()
{
	//delete each individual movie
	for(int x=0; x<numMovies; x++)
	{
		delete moviesArray[x];
	}
	//delete movies array
	delete [] moviesArray;
}


void MovieLibrary::resizeMovieArray()
{
	int max = maxMovies * 2; //increase size by 2
	cout << "\nResizing movieArray from " << maxMovies << " to " << max << ".\n";
	//make an array that is twice as big as the one I've currently got
	Movie** newMoviesArray = new Movie*[max];
	for(int x = 0; x < numMovies; x++)
	{
		newMoviesArray[x] = moviesArray[x];
	}
	delete [] moviesArray;
	moviesArray = newMoviesArray;
	maxMovies = max;
} 

void MovieLibrary::addMovieToArray() 
{
	char tempString[100];
	int year;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//add a movie
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	cout << "\nMOVIE YEAR: ";
	cin >> year;
	cin.ignore();
	cout << "\nMOVIE GENRE: ";
	cin.getline(tempString, 100);
	genre = new Text(tempString);
	cout << "\nMOVIE RATING: ";
	cin.getline(tempString, 100);
	rating = new Text(tempString);
	cout << "\nSTAR RATING (out of 10): ";
	cin >> numStars;
	
	//create the movie
	Movie* oneMovie = new Movie(title, year, genre, rating, numStars);
	
	//add the movie to the library
	if(numMovies == maxMovies)
		resizeMovieArray();	//increase size by 2

	moviesArray[numMovies] = oneMovie;
	
	(numMovies)++;

}

void MovieLibrary::removeMovieFromArray()
{
	int movieChoice;
	
	if(numMovies <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
		
		while(movieChoice < 1 || movieChoice > numMovies)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
			cin >> movieChoice;
		}

		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = moviesArray[movieIndexToBeRemoved]->getMovieTitle();
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		//destroy this movie
		delete moviesArray[movieIndexToBeRemoved];
		
		int numElementsToMoveBack = (numMovies) - 1;
		
		for(int x = movieIndexToBeRemoved; x < numElementsToMoveBack; x++)
		{
			moviesArray[x] = moviesArray[x+1]; //move array elements!
		}
		
		//set the last movie to a null pointer
		moviesArray[numElementsToMoveBack] = NULL;
		
		//decrement the current number of movies
		(numMovies)--;
		
		
	}
}


void MovieLibrary::displayMovies()
{
	if(numMovies > 0)
	{
		for(int x=0; x < (numMovies); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			moviesArray[x]->printMovieDetails(); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void MovieLibrary::displayMovieTitles()
{
	Text* movieTitle;
	
	for(int x=0; x<numMovies; x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieTitle = moviesArray[x]->getMovieTitle();
		movieTitle->displayText();
	}
}

void MovieLibrary::loadMoviesFromFile(char *filename)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieYear; //year released
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = new Text(temp);//create a text for the movie title
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieYear, genre, rating, movieNumStars);
			
			//now add this movie to the library
			
			if(numMovies == maxMovies)
				resizeMovieArray();	//increase size by 2

			moviesArray[numMovies] = oneMovie;
			
			(numMovies)++;
			
			//confirm addition to user
			cout << endl;
			title->displayText();
			cout << " was added to the movie library!\n";
						
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			numMoviesReadFromFile++;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void MovieLibrary::saveToFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x<numMovies; x++)
	{
		moviesArray[x]->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}

/*
int MovieLibrary::getNumMovies() const
{
	return numMovies;
}


int MovieLibrary::getMaxMovies() const
{
	return maxMovies;
}
*/
/*
Movie** Movies::getMoviesArray() const
{
	return moviesArray;
}
*/
/*
Movie* Movies::getAMovieFromArray(int index) const
{
	return moviesArray[index];
}
*/


