#include <iostream>
using namespace std;

void func()
{
    int* arr = new int[5];
    arr = resizeArray(arr, 5*2);
}

int* resizeArray(int* a, size)
{
    int arr2[size];

    //int*arr2 = new int [size];
    for (int i = 0;)
    {}

}
char* func
{
    char arr[5]; //type is pointer
    //getline(arr...)
    return arr; //type is character pointer--returning a pointer to an array
}

void func2()
{
    char* text = func();
    cout << text[3];
}