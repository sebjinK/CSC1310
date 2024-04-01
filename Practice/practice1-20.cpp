#include <iostream>
using namespace std;

class book
{
    private: 
        string* stuff;
        ///object* obj;
        ///object** obj; -- array of pointers -- each block holds an array which basically means 2d array
    public:
        book() //constructor funciton
        {
            stuff = new string[5];
            ///obj = new object; -- object is a pointer to an object--not an array meaning no brackets
        }
        ~book() //destructor function
        {
            delete [] stuff;
            ///delete obj;
        }
};


int main()
{
    book b1* = new book(); // pointer to an object within class book
    book b2();// object 

    b1->stuff; //pointer to object needs arrow
    b2.stuff; //object

    /*
    the reason you could change objects to pointers would be because the number of objects becomes too big to process
    so instead of having 50 different copies of an object, we use pointers to point to one function in main
    think of pointers like an address - objects are like building a new copy of your house at someone else's home
    pointers are the address you use to get to the house
    */

    ///book* arr
    ///cout << arr[4].stuff; = 1 pointer object
    /// cout << arr[3]->stuff; = 1 pointer

    ///book** arr = new...;
    ///cout << arr[3][4].stuff; - 2 pointer object
    ///cout << arr[5][5]->stuff; - 2 pointer 

    ///delete [][] object is NOT how you delte them
    
    /* 
    ~book() (DESTRUCTOR FUNCTION)
    {
        for (i = 0; i < x; i++) (# OF FOR LOOPS DEPENDS ON NUMBER OF POINTERS  POIN)
            {delete [] obj[i];}
        delete obj;
    }
    */
    int arr* = new int[5]; //points back to an array integer (will point back to position 5)

    delete [] arr; //since arr is pointing to one integer on the array, 
                   //nothing else gets deleted if you just type delete arr; 
                   //instead you can delte the whole array with delte [] arr;  
                   //since that points to the whole array
    return 0;
}
