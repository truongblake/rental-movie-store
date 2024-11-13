#include <iostream>
#include "movie.h"
#ifndef DRAMA
#define DRAMA
class Drama : public Movie {
public:
    // Constructor initializing Drama movie details
    Drama(int stock, std::string title, std::string director, int month, int year, std::string majorActor)
        : Movie('D', stock, director, title, month, year, majorActor) {
    }

    // Override comparison operator for sorting
    bool operator<(const Movie& other) const override {
        // Drama movies are sorted by Director, then Title
        if (this->getDirector() == other.getDirector()) {
            return this->getTitle() < other.getTitle();
        }
        return this->getDirector() < other.getDirector();
    }
    // Override equality operator for comparison
    bool operator==(const Movie& other) const override {
        // Two Drama movies are equal if they have the same director and title
        return this->getDirector() == other.getDirector() &&
               this->getTitle() == other.getTitle();
    }

    // Override display method to show Comedy movie details
    void display() const override {
        std::cout << "Drama Movie: " << getTitle() << std::endl; 
        std::cout << "Stock: " << getStock() << std::endl; 
        std::cout << "Directed by: " << getDirector() << std::endl; 
        std::cout << "Released in: " << getYear() << std::endl;
    }

};
#endif