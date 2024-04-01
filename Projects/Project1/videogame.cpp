/*
Name:               videogame.cpp
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            source file containing the function definitions required for the VideoGame class.
*/
#include "videogame.h"

VideoGameConstructor(Text* title, Text* dev, Text* publisher, int yearPublished)
{
    gameTitle = title;
    gameDeveloper = dev;
    gamePublisher = publisher;
    year = yearPublished;
}
VideoGameDestructor()
{
    delete gameTitle;
    delete gameDeveloper;
    delete gamePublisher;
}
void printVideoGameDetails()
{
    cout << right << setw(30) << "--------Video Game" 
}