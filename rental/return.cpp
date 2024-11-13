#include <iostream>
#include "transaction.h"
#include "movie.h"
#include "customer.h"

// The 'Return' class inherits from the 'Transaction' class
class Return : public Transaction {
public:
    // Constructor for the 'Return' class
    Return(Customer* customer, Movie* movie) : Transaction() {
        this->actionType = 'R';
        this->movie = movie; // Initializes the 'movie' pointer with the passed movie object
        this->customer = customer;
    }

    // Overrides the 'doTransaction' method from the 'Transaction' base class
    bool doTransaction() override {
        
        this->movie->returnMovie();
        return true;
    }

    // Display method for the 'Return' class
    void display() {
        // Can be used to display information about the return transaction
        std::cout << "Return: ";
        std::cout << this->movie->getTitle() << std::endl; 
    }

private:
    Movie* movie; // Pointer to a 'Movie' object representing the movie being returned
    Customer* customer;
};
