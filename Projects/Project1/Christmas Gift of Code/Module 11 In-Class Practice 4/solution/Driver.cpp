/*
	Filename: 	Driver.cpp
	Author:		April Crockett
	Date:		11/15/2022
	Purpose:	Module 11 In-Class Practice 4
*/
#include "IceCream.h"

int main()
{
	IceCream** iceCreamArray;
	string cone, flavor, topping;
	double price;
	int iceCreamNum;
	
	cout << "\nHow many ice creams would you like?" << endl;
	cin >> iceCreamNum;
	cin.ignore();
	
	//dynamically allocate a new array of IceCream of size iceCreamNum
	iceCreamArray = new IceCream* [iceCreamNum];
	
	for(int i = 0; i < iceCreamNum; i++)
	{
		cout << "\n\nEnter data for ice cream " << i+1 << ":\n\n";
		cout << "Type of cone:\t\t";
		getline(cin, cone);
		cout << "What flavor?\t\t";
		getline(cin, flavor);
		cout << "What topping?\t\t";
		getline(cin, topping);
		cout << "Price \t\t\t$";
		cin >> price;
		cin.ignore();
		
		//Dynamically allocate a new IceCream and assign it to iceCreamArray[i]
		iceCreamArray[i] = new IceCream(cone, flavor, topping, price);
	}
	
	//print the ice cream
	cout << "\n\nYOUR ICE CREAM ORDER:\n";
	for(int i = 0; i < iceCreamNum; i++)
	{
		cout << "Ice cream number " << i + 1 << endl;
		iceCreamArray[i]->printIceCream();
	}
	for (int i = 0; i < iceCreamNum; i++)
	{
		delete iceCreamArray[i];
	}
	delete [] iceCreamArray;
	
	return 0;
}