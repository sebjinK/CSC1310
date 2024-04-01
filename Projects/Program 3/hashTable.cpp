#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
#include "sha256.h"
#include "sha256.cpp"
using namespace std;

/*/////////////////////////////////////////////////
Function name:  hashTable constructor 
•	Parameters: an int, the amount of space to 
				allocate for the array
•	Purpose:  dynamically allocates a new array of 
	entry pointers and sets every array element to null. 
	It also seeds the random number generator that 
	we’ll use to generate the users’ salts.
*/
hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	//declare array
	hashArray = new entry * [size];
	tableSize = size;
	
	//make list null
	for(int i = 0; i < tableSize; i++) {
		hashArray[i] = NULL;
	}
	srand(time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
	{
		s = s + char('!' + (rand() % 93));
	}
	return s;
}
/*/////////////////////////////////////////////////
Function name:  hashTable destructor
•	Parameters: none
•	Purpose:  deletes every user from the 
	has table by looping through the array and
	deleting the linked list in every bucket.
*/
hashTable::~hashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		delete hashArray[i]; 
	}
	//fixme: does this work
	delete [] hashArray;
}
/*/////////////////////////////////////////////////
Function name:  getSalt
•	Parameters: a string for the user we’re grabbing a salt from
•	Returns: a string, which is the salt we’re grabbing

•	Purpose: to be able to append the salt to a password before we 
	hash it

•	Specifications: this call the getEntry function to 
	find the user associated with the key we got as a 
	parameter. Once we have a user, we can call the 
	getSalt function for that user. Think about what 
	needs to happen if that user isn’t in the table.
*/
string hashTable::getSalt(string passedString)
{
	entry * hashEntry = this->getEntry(passedString);

	if (hashEntry)
		return hashEntry->getSalt();		
	else
		return "no returned string";

	/*
	entry * checkToSeeIfUserExists = this->getEntry(passedUsername);

	if (checkToSeeIfUserExists != NULL)//if the check isn't NULL that means he has an entry, and we can grab the salt from that entry
	{
		return checkToSeeIfUserExists->getSalt(); //we return the salt that belongs to checkToSeeIfUserExists
	}
	else
	{
		cout << "\n\nError! User not found.Cannot send a salt back!\n" << endl;
	}
	
	*/
}
/*/////////////////////////////////////////////////
Function name:  addEntry
•	Parameters: three strings, which will be 
	sent to the entry constructor

•	Returns: void

•	Purpose: to add a new user to the table

•	Specifications: dynamically allocate a new entry, 
	call the hash function to determine which bucket the 
	new user will be stored in, and add them to the 
	list in that bucket. Make sure you aren’t adding a 
	username that already exists in the table.

*/
void hashTable::addEntry(string u, string s, string h)
{
	entry * hashEntry = new entry(u, s, h);
	int bucket = hash(u);

	if(hashArray[bucket] == NULL)
	{
		hashArray[bucket] = hashEntry;
	}

	else {
		//	set up the traverser to go through the list
		//	problem right now is that bucketList may be set up incorrectly
		//	
		entry * bucketList = hashArray[bucket]; 
		cout << "DEBUG: " << bucketList->getUserName();
		while (bucketList->next)
		{
			bucketList = bucketList->next;
		}
		bucketList->next = hashEntry;
		bucketList->next = NULL;
		hashArray[bucket] = bucketList;
}

	/*R's code :)

		entry * newEntry = new entry(uname, slt, pwd);
		int bucketIndex = hash(pwd);
		entry * holder = hashArray[bucketIndex];

		if (holder == NULL) {										//CASE 1; list is empty.								
		hashArray[bucketIndex] = newEntry;
	}
	else {														//CASE 2: list is not empty.
		cout << holder->getUsername() << endl;
		while ((holder->next != NULL) && (holder->getUsername() != uname)){
			holder = holder->next;
		}
		cout << "flag 3 " << endl;
		if (holder->getUsername() != uname){
			holder->next == newEntry;
		}
		else {
			cout << "Oops! That username is already in the system. Please enter a new username." << endl;
		}
	}*/
}
	/*//check through the array to make sure there is a bucket for this hash
	for (int i = 0; i < bucket; i++)
	{
		if (hashArray[i]->next == NULL && i == bucket)
		{
			make temp variable holding type table
			all element elements of hashArray[i] = all elements of hashEntry[i]
		}	
	}
	*/
	//make if statements checking if there is a number of next 
	//pointers within the list of the array box
	/*
	if (hashEntry[bucket]->next != NULL)
	{

	}
	*/	
	//if (userName == userName already in the table)
		//return ;
	//else
/*/////////////////////////////////////////////////
Function name:  validateLogin
•	Parameters: two strings, a username and password 
	(which has already been hashed)

•	Returns: a bool, which indicates whether or not 
	the login was successful.

•	Purpose: to check if the user has entered the 
	correct login credentials

•	Specifications: this calls the getEntry function 
	to find the data that goes with the username they 
	entered, then checks if the password hash that was 
	sent matches the password hash that was saved 
	under that username.

*/
bool hashTable::validateLogin(string userName, string pass)
{
	/*
	entry * validate = getEntry(userName);
	if (validate && validate->getHashedPwd() == pass)
		return true;
	else
		return false;
	*/
	int bucket = hash(userName);
	entry * validate = hashArray[bucket];
	while (validate && validate->getUserName() != userName)
		validate = validate->next;
	if (!validate) // check if username is there
		return false;
	string hashedPassedPass = sha256(pass + validate->getSalt());
	if (hashedPassedPass == validate->getHashedPwd()) // check if password is there
		return true;
	return false;
}
/*/////////////////////////////////////////////////
Function name:  removeUser
•	Parameters: two strings, a username and password 
	(which has already been hashed)

•	Returns: a bool, which indicates whether the user 
	was removed successfully

•	Purpose: to remove a user from the hash table

•	Specifications: First we need to find the user 
	who’s trying to remove themself. Once we’ve found 
	that user, we need to verify their login credentials 
	(don’t let someone delete a user without the correct 
	password, then anyone could delete any other user 
	in the system). Once we’ve verified that user, 
	then we can remove their entry from the table.
*/
bool hashTable::removeUser(string userName, string pass)
{
	//Hashes the key to find which bucket in hashArray stores the item
	int bucket = hash(userName);
	//Used for iterating through the linked list
	entry * i = hashArray[bucket];
	//Holds previous node
	entry * iPrev = NULL;
	if(!(this->validateLogin(userName, pass)))
		return false;
	while(i && i->getUserName() != userName){
		iPrev = i;
		i = i->next;
	}
	//If the name of the item in the bucket matches the item we're looking for, return the entry
	if (i && i->getUserName() == userName) {
		//Create a temporary node to hold the entry being deleted
		entry * removeMe = i;
		
		//Chain the linked list together without i
		iPrev->next = i->next;

		//Delete i
		delete i;
		return true;
	} 
	else
		return false;
	
} 

hashTable::entry::entry(string userName, string saltNum, string hashedPwd)
{
	this->username = userName;
	this->salt = saltNum;
	this->hashedPass = hashedPwd;
	this->next = NULL;
}