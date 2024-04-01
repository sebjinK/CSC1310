#include <iostream>

using namespace std;

int main()
{
    //pointers point to the numeric position of a label


    int x = 5; //the label would point to the label's address (ex. 0x83675)

    int* y = &x; //the ampersand points to the address of the pointer


    cout << x; //prints 5 - normal cout statement

    cout << &x; //prints 0x83675 - prints out the address of x since x is a normal variable

    cout << y; //prints 0x83675 - prints out the address of y = x or address of x since y is a pointer variable
    cout << *y; //5 - looks for the address of ointer y which is x

    cout << *&x; //prints 5 - first looks at &x to get the address of x and then looks at * to get the print value



    //pointers to arrays

    int* arr = new int [8]; //sets up a double array -- arr[0] = 0x38

    cout << *(arr + 3); // arr[3] = 0x41


    /*
    Questions:

    
    
    */
    return 0;
}