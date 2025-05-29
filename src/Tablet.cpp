#include "Tablet.hpp"
#include <iostream>
#include <sstream>

// Constructor
Tablet::Tablet(std::string type, std::string id, std::string brand, std::string cpuFam, double screenSize, double price) : Computer("Tablet", type, id, brand, cpuFam, price), screenSize(screenSize) {}

//display function
void Tablet::display() const {
    std::cout << "[Tablet]" << type << " | ID: " << id << " | Brand: " << brand << " | CPU Family: " << cpuFam << " | Screen Size: " << screenSize << "\" | Price: $" << price << std::endl;
}

//tablet attributes
void Tablet::update() {
    std::cout << "Updating tablet..." << std::endl; 
    std::string input;

    //brand inpput
    std::cout << "Brand (" << brand << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        brand = input;
    }

    //cpu family input
    std::cout << "CPU Family (" << cpuFam << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        cpuFam = input;
    }

    //screen size input
    std::cout << "Screen Size (" << screenSize << "\"): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        screenSize = std::stod(input);
    }

    //price input
    std::cout << "Price ($" << price << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        price = std::stod(input);
    }
}
//toFileString function
std::string Tablet::toFileString() const {
    std::ostringstream oss;
    oss << category << "," << type << "," << id << "," << brand << "," << cpuFam << "," << screenSize << "," << price;
    return oss.str();
}