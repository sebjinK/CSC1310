#include <iostream>

using namespace std;

int fib (int);
int function (int);

int main()
{
    /*
    Recursion - 
    a recursive function is a function that calls itself
    */
    int x;
    cout << "Enter a number x: ";
    cin >> x;
    cout << function(x) << endl;

    cout << fib(x) << endl;

    return 0;
}

//recursive example
void message()
{
    cout << "This message is forever\n";
    message();
}

//in order to not come to infinite recursion, we use a base case--
//returns a value without makeing any more calls

//base case example
/*
(1)       ↓     Function call 1     <- (8)
(2)        ↓->        ->Function call 2   <-^ (8)
(4)         ↓->          ->Funciton call 3  <-^ (8)
(8)           ->              ->base Case     ^ (8)

*/

//recursion starts from the top and moves the return value down

int function(int num)
{
    cout << "VALUE OF NUM: " << num << endl;
    if (num <= 0) // base case
    {
        return 0;
    }
    else
    {
        return function(num-1) + num;
    }
}
int fib(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    else 
        return fib(n - 1) + fib(n - 2);
}