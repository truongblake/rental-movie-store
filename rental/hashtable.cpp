#include <iostream>
#include "hashtable.h"
#include "customer.h"
//needs to be implemented

HashTable::HashTable(): profiles(100,nullptr), size(100){
    
}

int HashTable::hashFunction(int key){
    return key % size;
}

void HashTable::insert(Customer* customer){

        int index = hashFunction(customer->getID());

        // Linear probing for collision resolution
        while (profiles[index] != nullptr && profiles[index]->getID() != customer->getID()) {
            index = (index + 1) % size;
        }

        if (profiles[index] != nullptr) { // overrides customer if they have an same ID
            delete profiles[index];
        }

        profiles[index] = customer;
}

Customer* HashTable::search(int id){
        int index = hashFunction(id);

        while (profiles[index] != nullptr) {
            if (profiles[index]->getID() == id) {
                return profiles[index];
            }
            index = (index + 1) % size;
        }

        return nullptr;
}

void HashTable::display(){
    for (int i = 0; i < size; ++i) {
        if (profiles[i] != nullptr) {
            std::cout << "Index: " << i << ", Customer ID: " << profiles[i]->getID() << ", Name: " << profiles[i]->getFirstName() << std::endl;
        }
    }
}