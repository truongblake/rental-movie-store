#include <iostream>
#include <string>
#include"movie.h"


// Default constructor for the Movie class
Movie::Movie(): genre(' '), stock(10), director(""), title(""),month(-1), year(-1) {
    // Initializes the movie with default values
}

// Parameterized constructor for the Movie class
Movie::Movie(char genre, int stock, std::string director, std::string title, int month, int year, std::string majorActor){
    this->genre = genre;           // Sets the movie's genre
    this->stock = stock;           // Sets the number of movies in stock
    this->director = director;     // Sets the movie's director
    this->title = title;           // Sets the movie's title
    this->year = year;             // Sets the year of the movie
    this->month = month;           // Sets the month of the movie
    if(majorActor != ""){
        this->majorActors.push_back(majorActor);
    }
}

// Decrease the stock of the movie by one, simulating a movie being borrowed
void Movie::borrow(){
    this->stock--;
}

// Increase the stock of the movie by one, simulating a movie being returned
void Movie::returnMovie(){
    this->stock++;
}

// Getter method for the movie's genre
char Movie::getGenre() const{
    return this->genre;
}

// Getter method for the movie's stock
int Movie::getStock() const{
    return this->stock;
}

// Getter method for the movie's director
std::string Movie::getDirector() const{
    return this->director;
}

// Getter method for the movie's title
std::string Movie::getTitle() const{
    return this->title;
}

// Getter method for the movie's year
int Movie::getYear() const{
    return this->year;
}

int Movie::getMonth() const{
    return this->month;
}

// Getter method for the movie's actor release date
std::vector<std::string> Movie::getMajorActors() const{
    
    return majorActors;
}

void Movie::addStock(int add){
    this->stock += add;
}

void Movie::addMajorActor(std::string majorActor){
    this->majorActors.push_back(majorActor);
}

