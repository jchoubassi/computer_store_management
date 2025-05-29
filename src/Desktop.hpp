#ifndef DESKTOP_HPP
#define DESKTOP_HPP

#include "Computer.hpp"
#include <iostream>

//
class Desktop : public Computer {
public:
    Desktop(std::string type, std::string id, std::string brand, std::string cpuFam, int memSize, int ssdSize, double price);
    void display() const override;
    void update() override;
    std::string toFileString() const override;
private:
    int memSize;
    int ssdSize;
};

#endif