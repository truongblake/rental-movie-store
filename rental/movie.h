#include <iostream>
#include <string>
#include <vector>
#ifndef MOVIE_H
#define MOVIE_H
class Movie{

public:
    Movie();
    Movie(char genre, int stock, std::string director, std::string title, int month, int year, std::string majorActor);
    virtual bool operator<(const Movie& other) const = 0;
    virtual bool operator==(const Movie& other) const = 0;
    virtual void display() const = 0;
    void borrow();
    void returnMovie();
    char getGenre() const;
    int getStock() const;
    void addStock(int add);
    int getYear() const;
    int getMonth() const;
    std::string getDirector() const;
    std::string getTitle() const;
    std::vector<std::string> getMajorActors() const;
    void addMajorActor(std::string majorActor);

protected:
    char genre;
    int stock;
    int month, year;
    std::string director;
    std::string title;
    std::vector<std::string> majorActors;
    
};
#endif