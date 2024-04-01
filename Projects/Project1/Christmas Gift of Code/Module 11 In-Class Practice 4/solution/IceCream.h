/*
	Filename: 	IceCream.h
	Author:		April Crockett
	Date:		11/15/2022
	Purpose:	Module 11 In-Class Practice 4
*/

#ifndef ICECREAM_H
#define ICECREAM_H

#include <iostream>
using namespace std;

class IceCream
{
	private:
		string cone;
		string flavor;
		string topping;
		double price;
			
	public:		
		//constructors
		IceCream();
		IceCream(string, string, string, double);
	
		//mutator functions
		void setCone(string c);
		void setFlavor(string f);
		void setTopping(string t);
		void setPrice(double p);
		
		//accessor functions
		string getCone() const;
		string getFlavor() const;
		string getTopping() const;
		double getPrice() const;
		
		//print function
		void printIceCream() const;
};
#endif






