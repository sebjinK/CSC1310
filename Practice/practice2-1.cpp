#include <iostream>

using namespace std;


int main()
{
    //stepthrough - one at a time

    /*
    array
    - access each index

    - check equivalennce
        if equal the program finishes
        if not equal we continue the program
    */
    int const size = 10;   
    int arr[size];
    int key;
    int high = 9, low = 0, mid;
    arr = fillData();

//split in half
while (mid != key && low < high)
{
    mid = ((high - low)/2);
    
    if (arr[mid] == key)
    {
        
    }
    else if (key < arr[mid])
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
    
}

//find arr[i] == key
for (int i = 0; i < 10; i++)
{
    if(arr[i] == key)
    {
        cout << "Nice job~ Found at " << i + 1;
        break;
    }
    /*
    else in the case that the thing isn't found
    cout << "Key not found";
    
    */
}

int i = 0;
while (arr[i] != key && i < 10)
{
    i++;
}
if (i < size)
    cout << "Key found at " << i + 1;
else 
    cout << "Key not found" << endl;
//cout << "We're done` Key found at " << i + 1;
    
    /*
    spilt in half check one half


    check =, <, or >

    if = done

    if < or > so left or right
    split set in half again


    ((high i - low i) / 2)
    
    
    */
    
    
    return 0;
}