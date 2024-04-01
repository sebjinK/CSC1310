#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
#include "sha256.h"
#include "sha256.cpp"
using std::string;
using std::cout;

hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	tableSize = size;
	hashArray = new entry*[tableSize];
	for(int i=0; i<tableSize; i++)
		hashArray[i] = NULL;
	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

hashTable::~hashTable(){

	for(int i=0; i < tableSize; i++){
		delete hashArray[i];		
	}
	delete [] hashArray;
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
		s = s + char('!' + (rand() % 93));
	return s;
}
hashTable:: entry* hashTable::getEntry(string username){
	int bucket = hash(username);
	entry* temp = hashArray[bucket];
	while(temp && temp->getUsername() != username)
		temp = temp->next;
	if(temp && temp->getUsername() == username)
		return temp;
	return NULL;
}

string hashTable::getSalt(string username){
	entry* temp = getEntry(username);
	string salt = temp->getSalt();
	return salt;

}
void hashTable::addEntry(string username,string salt, string pwd){	
	entry* newEntry = new entry(username,salt,sha256(pwd + salt));
	entry* travel = hashArray[hash(username)];

	if(hashArray[hash(username)] == NULL)
		hashArray[hash(username)] = newEntry;
	else {

		while(travel && travel->next != NULL)
			travel = travel->next;
		
		if(username == travel->getUsername()){
			std::cout << "User already exists" << std::endl;
			return;
		}
		travel->next = newEntry;
		travel = travel->next;
		travel->next = NULL;
		
	}
}

bool hashTable::validateLogin(string userName, string pass){
    int bucket = hash(userName);
	if (hashArray[bucket] == NULL)
	{
		return false;
	}
    entry* traverser = hashArray[bucket];
    while (traverser && traverser->getUsername() != userName){
		traverser = traverser->next; //traverses list looking for your mom
	}
	if(!traverser) 
	{
		return false;  
	}  
    string hashedPassedPass = sha256(pass + traverser->getSalt());
    if (hashedPassedPass == traverser->getHashedpwd())
	{ // check if password is there
        return true;
	}
	else
	{
    	return false;
	}
}
bool hashTable::removeUser(string username, string hashedPwd){
	int bucket = hash(username);
	entry* travel = hashArray[bucket];
	entry* tempDel = hashArray[bucket];
	entry* swap;
	while(travel && username != travel->getUsername())
		travel = travel->next; 

	if(!travel)
		return false;

	tempDel = travel;
	
	do{
		swap = travel->next;
		travel = NULL;
		hashArray[bucket] = swap;
	}while(travel);

	delete tempDel;
	travel = NULL;
	
		
	return true;
}
