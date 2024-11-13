#include <iostream>
#include "customer.h"
#include "movie.h"
#include "transaction.h"

// Definition of the 'Customer' class

// Default constructor for the 'Customer' class
Customer::Customer(int id, std::string firstName, std::string lastName){
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

// Method to display customer information
void Customer::display(){
    // This method is used to display the customer's information, such as name, ID, transaction history, etc.
    std::cout << this->id << " " << this->firstName << " " << this->lastName << std::endl; 
}

// Method to add a transaction to the customer's history
void Customer::addTransaction(Transaction* transaction){
    
    history.push_back(transaction);
    
}

// Method to retrieve and display the customer's transaction history
std::vector<Transaction*> Customer::getHistory(){
    // This method should retrieve and display the customer's history of transactions.
    // It loop through a stored list or vector of transactions and display each one.
    return history;
}

int Customer::getID(){
    return id;
}

std::string Customer::getFirstName(){
    return firstName;
}

std::string Customer::getLastName(){
    return lastName;
}
