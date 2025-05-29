#include "Laptop.hpp"
#include <iostream>
#include <sstream>

//Constructor
Laptop::Laptop(std::string type, std::string id, std::string brand, std::string cpuFam, int memSize, int ssdSize, double screenSize, double price) : Computer("Laptop", type, id, brand, cpuFam, price), memSize(memSize), ssdSize(ssdSize), screenSize(screenSize) {}

//display function
void Laptop::display() const {
    std::cout << "[Laptop]" << type << " | ID: " << id << " | Brand: " << brand << " | CPU Family: " << cpuFam << " | Memory Size: " << memSize << "GB | SSD Size: " << ssdSize << "GB | Screen Size: " << screenSize << "\" | Price: $" << price << std::endl;
}

//laptop attributes
void Laptop::update() {
    std::cout << "Updating laptop..." << std::endl; 
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

    //memory size input
    std::cout << "Memory Size (" << memSize << "GB): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        memSize = std::stoi(input);
    }

    //ssd size input
    std::cout << "SSD Size (" << ssdSize << "GB): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        ssdSize = std::stoi(input);
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
std::string Laptop::toFileString() const {
    std::ostringstream oss;
    oss << category << "," << type << "," << id << "," << brand << "," << cpuFam << "," << memSize << "," << ssdSize << "," << screenSize << "," << price;
    return oss.str();
}