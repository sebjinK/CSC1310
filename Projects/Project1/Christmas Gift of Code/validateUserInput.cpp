/*
	Filename: 	validateUserInput.cpp
	Author:   	April Crockett
	Date:		12/1/2022
	Purpose:    To demonstrate the best way to make sure a user 
				enters in a number when you are asking for
				numerical input.
*/
	
#include <iostream>
#include <cctype>  //for the tolower function
using namespace std;

int main()
{
	int num;
	char answer;
	
	do
	{
		cout << "\nEnter a number: ";
		/*
			The cin object in the following line of code will get the input from the buffer
			and then try to translate the data to the data type of the num variable (integer).
			If unable to translate the data to an integer, (if user entered a character or
			string of characters) then the fail error bit will be set to true on the stream.
			!cin is the same thing as !(cin.good()) and so if there is any error in the 
			input stream, then this will be true.
		*/
		while(!(cin >> num))
		{
			cout << "Please enter numbers only." << endl;
			cin.clear(); //clears all stream bits (good, bad, eof, fail)
			cin.ignore(10000, '\n'); //removes up to 10000 characters from buffer until a newline is removed
			cout << "\nEnter a number: ";
		}
		cout << "\nYou entered " << num << endl;
		
		cout << "\nRun again? (y or n):  ";
		cin.ignore(10000, '\n'); 
		cin.get(answer); //the get function gets one character (including whitespace) from user
	} while(tolower(answer) == 'y');
	
	cout << "\nBye.\n";
	return 0;
}