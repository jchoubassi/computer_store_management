#include "ComputerStore.hpp"
#include "Desktop.hpp"
#include "Laptop.hpp"
#include "Tablet.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

ComputerStore::~ComputerStore() {
    for (Computer* computer : inventory) {
        delete computer;
    }
    inventory.clear();
}

void ComputerStore::addComputer(Computer* computer) {
    inventory.push_back(computer);
}

void ComputerStore::displayInventory() const {
    for (const Computer* computer : inventory) {
        computer->display();
    }
}

void ComputerStore::sortInventory(){
    std::sort(inventory.begin(), inventory.end(), [](Computer* a, Computer* b){
        if (a->getCategory() != b->getCategory()) return a->getCategory() < b->getCategory();
        if (a->getType() != b->getType()) return a->getType() < b->getType();
        return a->getId() < b->getId();
    });

}

//----------- file functions -----------//
void ComputerStore::loadFromFile(const std::string& filename){
    std::ifstream file(filename);
    if (!file){
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::string category;
        std::getline(ss, category, ',');

        if (category == "Desktop"){
            std::string type, id, brand, cpuFam;
            int memSize, ssdSize;
            double price;

            std::getline(ss, type, ',');
            std::getline(ss, id, ',');
            std::getline(ss, brand, ',');
            std::getline(ss, cpuFam, ',');
            ss >> memSize; ss.ignore();
            ss >> ssdSize; ss.ignore();
            ss >> price;

            Computer* computer = new Desktop(type, id, brand, cpuFam, memSize, ssdSize, price);
            inventory.push_back(computer);
        }
        else if(category == "Laptop"){
            std::string type, id, brand, cpuFam;
            int memSize, ssdSize;
            double screenSize, price;

            std::getline(ss, type, ',');
            std::getline(ss, id, ',');
            std::getline(ss, brand, ',');
            std::getline(ss, cpuFam, ',');
            ss >> memSize; ss.ignore();
            ss >> ssdSize; ss.ignore();
            ss >> screenSize; ss.ignore();
            ss >> price;

            Computer* computer = new Laptop(type, id, brand, cpuFam, memSize, ssdSize, screenSize, price);
            inventory.push_back(computer);
        }
        else if(category == "Tablet"){
            std::string type, id, brand, cpuFam;
            double screenSize, price;

            std::getline(ss, type, ',');
            std::getline(ss, id, ',');
            std::getline(ss, brand, ',');
            std::getline(ss, cpuFam, ',');
            ss >> screenSize; ss.ignore();
            ss >> price;

            Computer* comp = new Tablet(type, id, brand, cpuFam, screenSize, price);
            inventory.push_back(comp);
        }
    }

    file.close();
    sortInventory(); //sort cause why not
}

void ComputerStore::saveToFile(const std::string& filename) const{
    std::ofstream file(filename);
    if(!file){
        std::cerr << "Error writing to file: " << filename << std::endl;
        return;
    }
    for (const Computer* computer : inventory){
        file << computer->toFileString() << std::endl;
    }
    
    file.close();
    std::cout << "Inventory saved to " << filename << std::endl;
}

//----------- search functions -----------//
void ComputerStore::searchCategory(const std::string& category) const{
    bool found = false;
    for (const Computer* computer : inventory){
        if (computer->getCategory() == category){
            computer->display();
        }
    }
    if (!found){
        std::cout << "No computers found in category: " << category << std::endl;
    }
}

void ComputerStore::searchCategoryAndType(const std::string& category, const std::string& type) const {
    for (const Computer* computer : inventory) {
        if (computer->getCategory() == category && computer->getType() == type) {
            computer->display();
        }
    }
}

void ComputerStore::searchID(const std::string& id) const {
    for (const Computer* computer : inventory) {
        if (computer->getId() == id) {
            computer->display();
            return;
        }
    }
    std::cout << "No computer found with ID: " << id << std::endl;
}

void ComputerStore::searchPrice(double price, bool greaterThan) const {
    for (const Computer* computer : inventory) {
        if ((greaterThan && computer->getPrice() > price) ||
            (!greaterThan && computer->getPrice() < price)) {
            computer->display();
        }
    }
}

// ---- change inventory ---- //
//for add computer to check if ID taken
bool ComputerStore::idExists(const std::string& id) const {
    for (const Computer* comp : inventory) {
        if (comp->getId() == id) return true;
    }
    return false;
}

//Updating a current computer
void ComputerStore::updateComputer(const std::string& id){
    for (Computer* computer : inventory){
        if (computer->getId() == id){
            std::cout << "Current computer info: ";
            computer->display();
            std::cout << "Update computer info: " << std::endl;
            computer->update();
            std::cout << "Computer updated." << std::endl;
            
            sortInventory();
            return;
        }
    }
    std::cout << "No computer found with ID: " << id << std::endl;
}

//delete computer
void ComputerStore::deleteComputer(const std::string& id){
    for (auto it = inventory.begin(); it != inventory.end(); ++it){
        if((*it)->getId() == id){
            std::cout << "Deleting computer." << std::endl;
            (*it)->display();

            delete *it;
            inventory.erase(it);
            std::cout << "Computer deleted: " << id << std::endl;
            return;
        }
    }
    std::cout << "No computer found with ID: " << id << std::endl;
}