/*
Name:               videogame.h
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            header file for a VideoGame class, which has data and functions describing a single video game.
*/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "text.h"
using namespace std;

class VideoGame
{
    private:
        Text * gameTitle;
        Text * gameDeveloper;
        Text * gamePublisher;
        int year;
    public:
        VideoGameConstructor(Text*, Text*, Text*, int);
        VideoGameDestructor();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(fstream&);
        void getVideoGameTitle();//accessor Function

};

#endif