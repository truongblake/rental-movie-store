#include <iostream>
#include "movie.h"
#ifndef CLASSIC
#define CLASSIC
class Classic : public Movie {
public:

    // Constructor initializing Classic movie details
    Classic(int stock, std::string title, std::string director, int month, int year, std::string majorActor)
        : Movie('C', stock, director, title, month, year, majorActor) {
    }

    // Override comparison operator for sorting
    bool operator<(const Movie& other) const override {
        // Assuming Classic movies are sorted by release date then actor
        if (this->getYear() == other.getYear()) {
            return this->getMajorActors() < other.getMajorActors();
        }
        return this->getYear() < other.getYear();
    }

    // Override equality operator for comparison
    bool operator==(const Movie& other) const override {
        // Two Classic movies are equal if they have the same year and actorReleaseDate
        return this->getYear() == other.getYear() && 
               this->getMajorActors() == other.getMajorActors();
    }

    // Override display method to show Classic movie details
    void display() const override {
        std::cout << "Classic Movie: " << getTitle() << std::endl;
        std::cout << "Stock: " << getStock() << std::endl; 
        std::cout << "Directed by: " << getDirector() << std::endl;
        std::cout << "Starring: ";
        for(std::string actor: this->getMajorActors()){
            std::cout << actor << " ";
        } 
        std::cout << std::endl;
        std::cout << "Released in: " << getMonth() << " " << getYear() << std::endl;
    }
    
};
#endif