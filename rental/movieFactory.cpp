#include "comedy.cpp"
#include "classic.cpp"
#include "drama.cpp"
#include "movie.h"
#include <iostream>
#ifndef MOVIE_F
#define MOVIE_F

class MovieFactory{

    public:
    
    MovieFactory(){

    }
    Movie* createClassic(int stock, std::string title, std::string director, int month, int year, std::string majorActor){
        return new Classic(stock, title, director, month, year, majorActor);
    }

    Movie* createDrama(int stock, std::string title, std::string director, int month, int year, std::string majorActor){
        return new Drama(stock, title, director, month, year, majorActor);
    }

    Movie* createComedy(int stock, std::string title, std::string director, int month, int year, std::string majorActor){
        return new Comedy(stock, title, director, month, year, majorActor);
    }
};
#endif