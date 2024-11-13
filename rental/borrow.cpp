#include <iostream>
#include "transaction.h"
#include "movie.h"
#include "customer.h"

// Borrow class inherits from Transaction and represents a borrow transaction
class Borrow : public Transaction
{

public:
    // Constructor initializing Borrow as a Transaction
    Borrow(Customer* customer, Movie* movie) : Transaction(){
        this->movie = movie;
        this->customer = customer;
    }

    // Override method to perform the transaction process
    bool doTransaction() override{
        
        if(this->movie->getStock() == 0){
            std::cout << "Out of Stock" << std::endl;
            return false;
        }
        this->movie->borrow();
        return true;
    }

    // Display method for Borrow transaction
    void display(){
        std::cout << "Borrowed: ";
        std::cout << this->movie->getTitle() << std::endl;
    }

private:
    Movie* movie;
    Customer* customer;
};