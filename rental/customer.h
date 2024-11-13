#include <iostream>
#include "transaction.h"
#include <vector>
#include "movie.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{

public:
    Customer(int id = 000, std::string firstName = "undefine", std::string lastName = "undefine");
    void display();
    void addTransaction(Transaction* transaction);
    std::vector<Transaction*> getHistory();
    int getID();
    std::string getFirstName();
    std::string getLastName();

private:
    std::vector<Transaction*> history;
    std::string firstName;
    std::string lastName;
    int id; 
};
#endif