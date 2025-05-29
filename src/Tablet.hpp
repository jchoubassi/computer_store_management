#ifndef TABLET_HPP
#define TABLET_HPP

#include "Computer.hpp"

class Tablet : public Computer {
public:
    Tablet(std::string type, std::string id, std::string brand, std::string cpuFam, double screenSize, double price);
    
    void display() const override;
    void update() override;
    std::string toFileString() const override;
private:
    double screenSize;
};

#endif