//namespaces

#include <iostream>

using namespace std;

//if we have a collection 
//of classes that describe similar types of objects,
//it would be sensible to 
//stick them into the same namespace

namespace furniture
{
    class chair
    {

    };
    class table
    {

    };
}

//accessing the namespace object
/*
furniture:: <- the colon is the scope resolution operator
ex.
furniture::table diningRoom
furniture::table coffeeTable
turniture::chair recliner
*/


/*
Templates - 


if you have two functions that are basically identical except for the parameters' data types
ex. void func (int x){monkeytype = x; I want to kill two people}
ex. void func (double x){monkeytype = x; I want to kill two people}

you see how long difficult and stupid it is to write both of them out? 

try instead:
*/ 
template <typename T, typename U> // will this apply to all templates?
class Numbers
{
    private:
        T number1;
        T number2;
    public:
        Numbers(T one, T two)
        {
            number1 = one;
            number2 = two;
        };
}
void func(T dataX, U stuff) //we pass T as an integer DUE TO IT BEING IDENTIFIED AS SUCH IN THE MAIN FUNCITON   
{
    T d2 = dataX; //T will pass as an integer for the rest of the FUNCTION - not for the rest of the program
    cout << dataX; 

    return d2;
}
 void Numbers::setNumberOne(T num)
 {

 }


/*
makefiles - 
manually compiling a large number of files can be tedious and time consuming

make keeps tarck of all the files you made changes to and will do all the hard stuff for you



*/


int main()
{
    double arr;
    int monkey = 1;

    func(monkey, stuff); //monkey will pass as an int to dataX, stuff will pass as double to stuff

    Numbers<double> myNumsI(T mynum1, TmyNum2)
    {
        
    }


    return 0;
}

