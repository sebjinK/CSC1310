/*
	Filename: 	IceCream.cpp
	Author:		April Crockett
	Date:		11/15/2022
	Purpose:	Module 11 In-Class Practice 3
*/

#include <iomanip>
#include "IceCream.h"

//default constructor
IceCream::IceCream()
{
	cone = "";
	flavor = "";
	topping = "";
	price = 0.0;
}

//overloaded constructor
IceCream::IceCream(string c, string f, string t, double p)
{
	cone = c;
	flavor = f;
	topping = t;
	price = p;
}

//mutator functions
void IceCream::setCone(string c)
{
	cone = c;
}
void IceCream::setFlavor(string f)
{
	flavor = f;
}
void IceCream::setTopping(string t)
{
	topping = t;
}
void IceCream::setPrice(double p)
{
	price = p;
}
		
//accessor functions
string IceCream::getCone() const
{
	return cone;
}
string IceCream::getFlavor() const
{
	return flavor;
}
string IceCream::getTopping() const
{
	return topping;
}
double IceCream::getPrice() const
{
	return price;
}

//printIceCream function
void IceCream::printIceCream() const
{
	cout << setprecision(2) << fixed;
	cout << "Cone:\t\t" << cone << endl;
	cout << "Flavor:\t\t" << flavor << endl;
	cout << "Topping:\t" << topping << endl;
	cout << "Price\t\t" << price << endl;
}