#include <iostream>
#include "movie.h"
#include <map>
#include "hashtable.h"

// Business class responsible for managing movies and customers
class Business
{
public:
    // Constructor for Business class   
    Business();

    // Method to build movie records from a file
    void buildMovies(std::ifstream& file);

    // Method to build customer records from a file
    void buildCustomers(std::ifstream& file);

    // Method to process transactions from a file
    void processTransaction(std::ifstream& file);

private:
    std::map<std::string, Movie*> inventory;
    HashTable profiles; 
};