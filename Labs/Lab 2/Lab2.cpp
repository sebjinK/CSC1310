/*
	Title:  Lab2.cpp
	Author: Sebjin Kennedy
	Date:  	2/1/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>	
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
    int num;
	int choice, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(0));
	string userString, userStrModified;
	
	do{
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
                cout << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x = 0; x < ARRAY_SIZE; x++)
				{
					myArray[x] = (rand() % 100) + 1; //puts a random num 1-100 into each element of the array
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x = 0; x < ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if ((isMember(myArray, num, ARRAY_SIZE)) == true)
                    cout << "Yes! " << num << " is in the array." << endl;
                else
                    cout << "No! " << num << " is NOT in the array."<< endl;
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				num = userString.length();
				stringReverser(userString, num);
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
						userStrModified.erase(x, 1);
					if(userStrModified[x] == ',') 
						userStrModified.erase(x, 1);
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				if (isPalindrome(userStrModified) == true)
				{	
					cout << "Yes, the string is a palindrome.\n";
					cout << userStrModified;
					cout << endl;
				}
				else
					cout << "No, the stirng is not a palindrome. \n";
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "The value of " << num1 << " + " << num2 << " = " << multiply(num1, num2) << endl;
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!

int sumOfNumbers(int num)//adds to itself 
{
    int currentNum;
    int finalNum;

    if (num <= 0) // base case
        return 0;
    else
    {
      currentNum = sumOfNumbers(num - 1) + num;
      finalNum += currentNum;
      return finalNum;
    }
}

bool isMember(int* arr, int arrValue, int size)
{   
    if (arr[size] == arrValue) // checks if the array has the value
        return true;
    else if (size > 0) // checks if the array has finished 
        return isMember(arr, arrValue, (size - 1));
    else //if the array finished then the value returned should be false
        return false;

}

void stringReverser(string passedStr, int strLength)
{	
	strLength--;
	cout << passedStr[strLength]; //will output the next character on the string
	if(strLength >= 0)
	{
		stringReverser(passedStr, strLength);
	}
}

bool isPalindrome(string passedStr)
{
	string strTmp;
	char strBegin;
	char strEnd;

	strEnd = passedStr.at(passedStr.length() - 1);
	strBegin = passedStr.at(0);
	if (strEnd == strBegin)
	{
		if (passedStr.length() <= 2)
			return true;

		strTmp = passedStr.substr(1, passedStr.length() - 2);
		/*
		R A C E C A R
		  A C E C A 
		    C E C
		      E
			urgay
		*/
		if(isPalindrome(strTmp))
			return true;
		
		else
			return false;
	}

	else
		return false;
}

int multiply(int number1, int number2)
{
	int total;
	if (number1 == 0 || number2 == 0)
		return 0;
	if (number2 == 1)
		return number1;
	else
		total = number1 + multiply(number1, number2 - 1);

	return total;
}
