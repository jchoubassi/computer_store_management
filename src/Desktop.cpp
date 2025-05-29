#include "Desktop.hpp"
#include <iostream>
#include <sstream>

//Constructor
Desktop::Desktop(std::string type, std::string id, std::string brand, std::string cpuFam, int memSize, int ssdSize, double price) : Computer("Desktop", type, id, brand, cpuFam, price), memSize(memSize), ssdSize(ssdSize) {}

//display function
void Desktop::display() const {
    std::cout << "[Desktop]" << type << " | ID: " << id << " | Brand: " << brand << " | CPU Family: " << cpuFam << " | Memory Size: " << memSize << "GB | SSD Size: " << ssdSize << "GB | Price: $" << price << std::endl;

}

//desktop attributes
void Desktop::update() {
    std::cout << "Updating desktop..." << std::endl; 
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

    //price input
    std::cout << "Price ($" << price << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        price = std::stod(input);
    }

}
//toFileString function 
std::string Desktop::toFileString() const {
    std::ostringstream oss;
    oss << category << "," << type << "," << id << "," << brand << "," << cpuFam << "," << memSize << "," << ssdSize << "," << price;
    return oss.str();
}