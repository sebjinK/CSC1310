#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using namespace std;

class hashTable
{
	private:
		class entry{
			private:
				string username;
				string salt;
				string hashedPass;
			public:				
				entry * next;
				entry(string, string, string);
				string getUserName(){return username;};
				string getSalt(){cout << endl << salt << endl;
				return salt;}
				string getHashedPwd(){return hashedPass;}
		};
		

		//add the attributes you need for the class---------------------------------------------------------
		/*///////////////////////////////////////
		Function name:  hash

	•	Parameters: a string, the key we need to map
		to a bucket index

	•	Returns:  an int, the bucket index our key 
		is mapped to

	•	Purpose: map a key onto a bucket to 
		figure out where it belongs in the hash 
		table

	•	Specifications: this function is written 
		for you, so don’t touch it! 
		It maps a string onto an integer by adding 
		together the ascii values of each character in 
		the string. This is probably the worst possible 
		way to map a string in a hash table because 
		it has a high chance of collisions. We’re doing
		it this way because I’ve designed it for you to 
		have a lot of collisions.
		*/
		int hash(string);
		/*///////////////////////////////////////
		Function name:  getEntry
		•	Parameters: a string, the key we’re 
			looking up in the table

		•	Returns:  an entry pointer, all the 
			data associated with the key the we passed
			
		•	Purpose: retrieve a user for use in other 
			functions

		•	Specifications: apply the hash function
			to the key to figure out which bucket we
			need to look in, traverse the list in that
			bucket until we find the node with a
			matching key, then return that node 
			once we’ve found it. Think about what you 
			need to do if that key doesn’t correspond 
			with an entry in the table.
		*/
		hashTable::entry * getEntry(string key)
		{
			//STEP 1: FIND THE BUCKET WITHIN THE ARRAY
			//Find which bucket in hashArray stores the item
			int bucket = hash(key);
			//Used for iterating through the linked list
			entry * bucketNodeTraverser = hashArray[bucket];
			//STEP 2: TRAVERSE LINKED LIST IN THAT BUCKET UNTIL WE FIND THE RIGHT ENTRY. WE DO THIS BY MATCHING THE USERNAMES.
			while(bucketNodeTraverser && bucketNodeTraverser->getUserName() != key){ //WHILE LOOP TO FIND THE RIGHT ENTRY
				bucketNodeTraverser = bucketNodeTraverser->next;
				if (bucketNodeTraverser->getUserName() == username)
				{
					return bucketNodeTraverser; //trainstation analogy
				}
			}
			else{
				return NULL; //RETURN NOTHING IF IT ISN'T FOUND
			}
		}
		/* 
		{
			//Hashes the key to find which bucket in hashArray stores the item
			int bucket = hash(key);
			//Used for iterating through the linked list
			entry * i = hashArray[bucket];
			while(i && i->getUserName() != key){
				i = i->next;
			}
			//If the name of the item in the bucket matches the item we're looking for, return the entry
			if (i && i->getUserName() == key) {
				return i;
			} 
			return NULL;
		}
		*/
		int tableSize;
		entry ** hashArray;
	public:
		//add all the functions you need--------------------------------------------------------------------
		hashTable(int);//passes allocated amount of space for the array
		~hashTable();
		string getSalt(string);//passes string from user we're getting salt from
		string generateSalt();
		void addEntry(string, string, string);
		bool validateLogin(string, string);//passing username and hasedPassword
		bool removeUser(string, string);//removes user while passes username and password
};

#endif