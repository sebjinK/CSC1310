/*
Name:               videogamelibarary.h
Author:             Sebjin Kennedy
Date:               Feburary 7th, 2023

Required Files:     
driver.cpp      text.h      text.cpp    videogame.h
videogame.cpp   videogamelibrary.cpp    videogamelibrary.cpp

Purpose:            header file for a VideoGameLibrary class, 
                    which has data and functions describing a video game library (multiple games)
*/
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include "videogame.h"

using namespace std;


class videoGameLibrary
{
    private:
        VideoGame ** VideoGamesArray;
    public:
        void resizeVideoGameArray();
        void videoGameLibraryConstructor(int);
        void videoGameLibraryDestructor();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGameFromFile(char*);
        void removeVideoGamesFromArray();
        void saveToFile(char*);
};
#endif