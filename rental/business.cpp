#include <iostream>
#include "business.h"
#include <string>
#include <fstream>
#include "movie.h"
#include "comedy.cpp"
#include "drama.cpp"
#include "classic.cpp"
#include "customer.h"
#include "return.cpp"
#include "borrow.cpp"
#include "movieFactory.cpp"


Business::Business(){

}

void Business::buildMovies(std::ifstream& file) {
    std::string title, director, firstName, lastName;
    std::string skipLine;
    char type, delimiter;
    int stock, month, year;
    MovieFactory factory;

    while (file >> type) {
        file >> delimiter;
        if (type == 'F' || type == 'D') { //F, 10, Nora Ephron, Sleepless in Seattle, 1993
            file >> stock >> delimiter; 
            getline(file, director, ',');
            getline(file, title, ',');
            title = title.substr(1);
            file >> year;
            if (type == 'F') {
                // Process and add a Comedy movie
                inventory[title] = factory.createComedy(stock, title, director, -1, year, "");
            } else {
                // Process and add a Drama movie
                inventory[title] = factory.createDrama(stock, title , director, -1, year, "");
            }
        } else if (type == 'C') { //C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
            file >> stock >> delimiter;
            getline(file, director, ',');
            getline(file, title, ',');
            title = title.substr(1);
            file >> firstName >> lastName;
            file >> month >> year;
            getline(file, skipLine,'\n');
            // Process and add a Classic movie
            if(inventory[title] != nullptr){ //add major actor to same movie and increase stock
                inventory[title]->addStock(stock);
                inventory[title]->addMajorActor(firstName + " " + lastName);
            }else{
                inventory[title] = factory.createClassic(stock, title, director, month, year, firstName + " " + lastName);
            }
            
        } else {
            getline(file, skipLine, '\n');
        }
    }

    std::cout << "Initial Movies Inventory" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    for(const auto& pair: inventory){
        std::cout << "----------------------------------------------" << std::endl;
        Movie* movie = pair.second;
        movie->display();
        std::cout << "----------------------------------------------" << std::endl;
    }

}

void Business::buildCustomers(std::ifstream& file) {
    int id;
    std::string lastName, firstName;
    while (file >> id) {
        // Assuming the line is correctly formatted as "ID LastName FirstName"
        file >> lastName;
        file >> firstName;
        Customer* newCustomer = new Customer(id, firstName, lastName);
        profiles.insert(newCustomer);
    }
    std::cout << "Intial Customers" << std::endl;
    std::cout << "///////////////////////////////////////////" << std::endl;
    profiles.display();
}

void Business::processTransaction(std::ifstream& file) {
    
    char actionType;
    std::string skipLine;
    while (file >> actionType) {
        if (actionType == 'B'){
            // Process Borrow transaction
            int customerID, month, year;
            char mediaType, movieType;
            std::string title, director, firstName, lastName, majorActor;
            file >> customerID >> mediaType >> movieType;
            Customer* customer = profiles.search(customerID); //acquire customer object through customerID

            if(customer == nullptr || mediaType != 'D'){ //if customer id or mediatype is not valid we just skip line
                getline(file, skipLine, '\n');
                continue;
            }
            
            //process date first then name
            if(movieType == 'F'){
                getline(file, title, ',');
                file >> year; 
                auto movieExist = inventory.find(title.substr(1));
                if(movieExist != inventory.end()){ //checks map to see if movie exist
                    Movie* movie = inventory[title.substr(1)];
                    Borrow* borrow = new Borrow(customer, movie);
                    if(borrow->doTransaction()) customer->addTransaction(borrow);
                }else{
                    getline(file, skipLine, '\n'); 
                }
            }
            else if(movieType == 'D'){
                getline(file, director, ',');
                getline(file, title, ',');
                auto movieExist = inventory.find(title.substr(1)); //checks map to see if movie exist
                if(movieExist != inventory.end()){
                    Movie* movie = inventory[title.substr(1)];
                    Borrow* borrow = new Borrow(customer, movie);
                    if(borrow->doTransaction()) customer->addTransaction(borrow);
                }else{
                    getline(file, skipLine, '\n');
                }
            }
            else if(movieType == 'C'){
                file >> month >> year >> firstName >> lastName;
                majorActor = firstName + " " + lastName;
                for(const auto& pair: inventory){
                    Movie* movie = pair.second;
                    
                    for(std::string actor: movie->getMajorActors()){ 
                        if(actor == majorActor && movie->getMonth() == month && movie->getYear() == year){
                            Borrow* borrow = new Borrow(customer, movie);
                            if(borrow->doTransaction()) customer->addTransaction(borrow);
                        }
                    }
                    
                }
            }else{
                getline(file,skipLine,'\n');
            }
        }
        else if(actionType == 'R'){
            // Process Return transaction
            int customerID, month, year;
            char mediaType, movieType;
            std::string title, director, firstName, lastName, majorActor;
            file >> customerID >> mediaType >> movieType;
            Customer* customer = profiles.search(customerID);
            if(customer == nullptr || mediaType != 'D'){ 
                getline(file, skipLine, '\n');
                continue;
            }
            if(movieType == 'F'){ 
                getline(file, title, ',');
                file >> year;
                auto movieExist = inventory.find(title.substr(1));
                if(movieExist != inventory.end()){ //checks map to see if movie exist
                    Movie* movie = inventory[title.substr(1)];
                    Return* returning = new Return(customer, movie);
                    if(returning->doTransaction()) customer->addTransaction(returning);
                }else{
                    getline(file, skipLine, '\n');
                }
            }
            if(movieType == 'D'){
                getline(file, director, ',');
                getline(file, title, ',');
                auto movieExist = inventory.find(title.substr(1));
                if(movieExist != inventory.end()){ //checks map to see if movie exist
                    Movie* movie = inventory[title.substr(1)];
                    Return* returning = new Return(customer, movie);
                    if(returning->doTransaction()) customer->addTransaction(returning);
                }else{
                    getline(file, skipLine, '\n');
                }
            }
            if(movieType == 'C'){
                file >> month >> year >> firstName >> lastName;
                majorActor = firstName + " " + lastName;
                for(const auto& pair: inventory){ //checks map to see if movie exist
                    Movie* movie = pair.second;
                    for(std::string actor: movie->getMajorActors()){
                        if(actor == majorActor && movie->getMonth() == month && movie->getYear() == year){
                            Return* returning = new Return(customer, movie);
                            if(returning->doTransaction()) customer->addTransaction(returning);
                        }
                    }
                }
                
            }else{
                getline(file,skipLine,'\n');
            }
            
        } 
        else if (actionType == 'I') {
            // Process Inventory transaction
            std::cout << "INVENTORY" <<std:: endl;
            std::cout << "///////////////////////////////////////////////////////////////////" << std::endl;
            for(const auto& pair: inventory){
                std::cout << "----------------------------------------------" << std::endl;
                Movie* movie = pair.second;
                movie->display();
                std::cout << "----------------------------------------------" << std::endl;
            }
            
        } 
        else if (actionType == 'H') {
            // Process History transaction
            int customerID;
            // Acquire customer object from Hashtable
            file >> customerID;
            Customer* customer = profiles.search(customerID);
            if(customer == nullptr){ //if customer id is not valid we just skip line
                getline(file, skipLine, '\n');
                continue;
            }
            // Show the history of the customer
            std::vector<Transaction*> history = customer->getHistory();
            std::cout << "History of" << std::endl;
            std::cout << "ID: " << customerID << ", Name: " << customer->getFirstName() << " " << customer->getLastName() << ":" << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
            for(int i = 0; i < history.size(); i++){
                history[i]->display();
            }
        } 
        else {
            getline(file, skipLine, '\n'); // skip this line if invalid actionType
        }
    }
}