#include <iostream>
#include <vector>
#include "customer.h"
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
class HashTable{

private:
    std::vector<Customer*> profiles;
    int size;
    int hashFunction(int key);

public:

    HashTable();
    void insert(Customer* customer);
    Customer* search(int customerID);
    void display(); //debugging purposes
    
};
#endif