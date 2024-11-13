#include <iostream>
#include "movie.h"
#ifndef COMEDY
#define COMEDY

class Comedy : public Movie {
public:

    // Constructor initializing Comedy movie details
    Comedy(int stock, std::string title, std::string director, int month, int year, std::string majorActor)
        : Movie('F', stock, director, title, month, year, majorActor) {
    }

    // Override comparison operator for sorting
    bool operator<(const Movie& other) const override {
        // Comedy movies are sorted by Title, then Year it released
        if (this->getTitle() == other.getTitle()) {
            return this->getYear() < other.getYear();
        }
        return this->getTitle() < other.getTitle();
    }
    // Override equality operator for comparison
    bool operator==(const Movie& other) const override {
        // Two Comedy movies are equal if they have the same title and year
        return this->getTitle() == other.getTitle() && 
               this->getYear() == other.getYear();
    }

    // Override display method to show Comedy movie details
    void display() const override {
        std::cout << "Comedy Movie: " << getTitle() << std::endl; 
        std::cout << "Stock: " << getStock() << std::endl; 
        std::cout << "Directed by: " << getDirector() << std::endl; 
        std::cout << "Released in: " << getYear() << std::endl;
    }

};

#endif