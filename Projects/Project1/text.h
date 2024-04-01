/*
Name:               text.h
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            header file for a Text class, which is your own version of the C++ String Class
*/
#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>

using namespace std;

class Text
{
    private:
        int textLength;
        const char * textArray;
    public:
        textConstructor(const char*);
        textDestructor(char*);
        void displayText() const;
        void getText() const;//accessor function
        void getLength() const;//accessor function
/*
display text, get text, get length is constant as it would screw over the 
program if they wreen't constant 

*/
};
#endif 