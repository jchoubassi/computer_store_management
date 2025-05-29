#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <iostream>
#include <string>

class Computer{

//
public:
    Computer (std::string category, std::string type, std::string id, std::string brand, std::string cpuFam, double price);

    virtual void display() const = 0;
    virtual void update() = 0;
    virtual std::string toFileString() const = 0;

    std::string getCategory() const;
    std::string getType() const;
    std::string getId() const;
    double getPrice() const;

    virtual ~Computer(){}
protected:
    std::string category;
    std::string type;
    std::string id;
    std::string brand;
    std::string cpuFam;
    double price;
};

#endif