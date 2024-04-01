/*
Name:               text.cpp
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            source file containing function definitions required for the Text class
*/
#include "text.h"

int* Text::getLength() const //returns private member length of text
{
    return *textLength;
}

char* Text::getText() const//returns private member array of characters
{
    return *textArray[textLength];
}

void Text::textConstructor(char* textArray) //constructs a new array in current array and uses a for loop to make each element of currentArray = textArray
{
    char * currentArray;
    currentArray = new char [textLength + 1];

    for (int i = 0; i < textLength + 1; i++)
    {
        textArray[i] = currentArray[i];
    }
}

void Text::textDestructor(char* textArray)//destroys the 2d text array one element at a time then deletes the array as a whole
{
    for (int i = 0; i < textLength + 1; i++)
    {
        delete textArray[i];
    }
    delete [] textArray;
    cout << "\nText destructor: Released memory for textArray";
}

void Text::displayText() const//outputs the text array
{  
    cout << textArray << endl;
}
