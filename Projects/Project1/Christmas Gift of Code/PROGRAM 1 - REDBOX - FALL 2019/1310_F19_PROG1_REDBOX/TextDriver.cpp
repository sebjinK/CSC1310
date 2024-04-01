#include <iostream>
#include "Text.h"

using namespace std;

int main()
{
	Text* name;
	name = new Text("Llama");

	name->displayText();
	cout << endl;
	
	delete name;
	
	return 0;
}