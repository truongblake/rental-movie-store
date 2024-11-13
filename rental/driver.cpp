#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"
#include "customer.h"
#include "business.h"
#include "hashtable.h"

int main(){

    Business rentalMovieStore;

    std::ifstream file1("data4movies.txt");
    std::ifstream file2("data4customers.txt");
    std::ifstream file3("data4commands.txt");

    if(!file1.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    rentalMovieStore.buildMovies(file1);
    rentalMovieStore.buildCustomers(file2);
    rentalMovieStore.processTransaction(file3);
}