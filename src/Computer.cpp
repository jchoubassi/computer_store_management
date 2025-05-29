#include "Computer.hpp"

//Constructor
Computer::Computer(std::string category, std::string type, std::string id, std::string brand, std::string cpuFam, double price) : category(category), type(type), id(id), brand(brand), cpuFam(cpuFam), price(price) {}

//Getter functions
std::string Computer::getCategory() const {
    return category;
}
std::string Computer::getType() const {
    return type;
}
std::string Computer::getId() const {
    return id;
}
double Computer::getPrice() const {
    return price;
}
