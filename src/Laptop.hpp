#ifndef LAPTOP_HPP
#define LAPTOP_HPP

#include "Computer.hpp"

//
class Laptop : public Computer {
public:
    Laptop(std::string type, std::string id, std::string brand, std::string cpuFam, int memSize, int ssdSize, double screenSize, double price);

    void display() const override;
    void update() override;
    std::string toFileString() const override;
private:
    int memSize;
    int ssdSize;
    double screenSize;
};

#endif
