#ifndef COMPUTERSTORE_HPP
#define COMPUTERSTORE_HPP

#include "Computer.hpp"
#include <iostream>
#include <string>
#include <vector>

class ComputerStore{
public:
    ~ComputerStore(); //clean

    void addComputer(Computer* computer);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    void displayInventory() const;
    void sortInventory(); 

    void searchCategory(const std::string& category) const;
    void searchCategoryAndType(const std::string& category, const std::string& type) const;
    void searchID(const std::string& id) const;
    void searchPrice(double price, bool greaterThan) const;

    bool idExists(const std::string& id) const;

    void updateComputer(const std::string& id);
    void deleteComputer(const std::string& id);

private:
    std::vector<Computer*> inventory;

};

#endif