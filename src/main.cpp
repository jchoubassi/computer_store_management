// Choubassi, Jenny, 23003517, Assignment 3
// 159.234, S1, 2025

#include <iostream>
#include <limits>
#include "ComputerStore.hpp"
#include "Desktop.hpp"
#include "Laptop.hpp"
#include "Tablet.hpp"

void clearCin(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//----- Add a new computer to store via user input -----
Computer* createNewComputer(const ComputerStore& store){
    std::string category, type, id, brand, cpuFam;
    double price;
    
    //----- Add properties -----//
    std::cout << "Enter category (Desktop/Laptop/Tablet): ";
    std::getline(std::cin, category);

    std::cout << "Enter type: ";
    std::getline(std::cin, type);

    std::cout << "Enter ID: ";
    std::getline(std::cin, id);
    if (store.idExists(id)){
        std::cout << "ID already exists. Please enter a unique ID." << std::endl;
        return nullptr;
    }

    std::cout << "Enter brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter CPU Family: ";
    std::getline(std::cin, cpuFam);

    std::cout << "Enter price: ";
    std::cin >> price;
    std::cin.ignore();

    //----- Create computer based on category -----//
    if (category == "Desktop"){
        int mem, ssd;
        std::cout << "Enter memory size (GB): ";
        std::cin >> mem;
        std::cout << "Enter SSD size (GB): ";
        std::cin >> ssd;
        std::cin.ignore();
        return new Desktop(type, id, brand, cpuFam, mem, ssd, price);
    }
    else if(category == "Laptop"){
        int mem, ssd;
        double screen;
        std::cout << "Enter memory size (GB): ";
        std::cin >> mem;
        std::cout << "Enter SSD size (GB): ";
        std::cin >> ssd;
        std::cout << "Enter screen size (inches): ";
        std::cin >> screen;
        std::cin.ignore();
        return new Laptop(type, id, brand, cpuFam, mem, ssd, screen, price);
    }
    else if(category == "Tablet"){
        double screen;
        std::cout << "Enter screen size (inches): ";
        std::cin >> screen;
        std::cin.ignore();
        return new Tablet(type, id, brand, cpuFam, screen, price);
    }
    else{
        std::cout << "Invalid category. Please enter Desktop/Laptop/Tablet." << std::endl;
        return nullptr;
    }

}

int main(){
    ComputerStore store;
    store.loadFromFile("computers.txt");

    int choice;
    do{
        std::cout << "\n--- Computer Store Menu ---" << std::endl;
        std::cout << "Please select an option: " << std::endl;
        //have corresponding numbers for each case below
        std::cout << "1. Display Inventory" << std::endl;
        std::cout << "2. Search by Category" << std::endl;
        std::cout << "3. Search by Category and Type" << std::endl;
        std::cout << "4. Search by ID" << std::endl;
        std::cout << "5. Search by Price" << std::endl;
        std::cout << "6. Add New Computer" << std::endl;
        std::cout << "7. Update Inventory" << std::endl;
        std::cout << "8. Delete Computer" << std::endl;
        std::cout << "9. Save Inventory to File" << std::endl;

        std::cout << "0. Exit" << std::endl;

        std::cin >> choice;
        clearCin();

        std::string input;
        double price;
        bool greaterThan;

        switch (choice){
            case 1:{//Display inventory
                store.displayInventory();
                break;
            }
            case 2:{ //Search by category
                std::cout << "Enter category (Desktop, Laptop, Tablet): ";
                std::getline(std::cin, input);
                store.searchCategory(input);
                break;
            }
            case 3:{ //Search by category and type
                std::string category, type;
                std::cout << "Enter category (Desktop, Laptop, Tablet): ";
                std::getline(std::cin, category);
                std::cout << "Enter type (Business, Gaming, Thin & Light): ";
                std::getline(std::cin, type);
                store.searchCategoryAndType(category, type);
                break;
            }
            case 4:{ //Search by ID
                std::cout << "Enter ID: ";
                std::getline(std::cin, input);
                store.searchID(input);
                break;
            }
            case 5:{ //Search by price
                std::cout << "Enter price: ";
                std::cin >> price;
                clearCin();
                std::cout << "Search for greater than or less than? (1 for greater, 0 for less): ";
                std::cin >> greaterThan;
                clearCin();
                store.searchPrice(price, greaterThan);
                break;
            }
            case 6:{ //Add new computer
                Computer* newComputer = createNewComputer(store);
                if(newComputer){
                    store.addComputer(newComputer);
                    std::cout << "New computer added to inventory." << std::endl;
                }
                else{
                    std::cout << "Failed to add new computer." << std::endl;
                }
                break;
            }
            case 7:{ //Update inventory
                std::string id; 
                std::cout << "Enter ID of computer to update: ";
                std::getline(std::cin, id);
                store.updateComputer(id);

                char saveChUpdate;
                std::cout << "Do you want to save the updated inventory? (y/n): ";
                std::cin >> saveChUpdate;
                clearCin();
                if (saveChUpdate == 'y' || saveChUpdate == 'Y'){
                    store.saveToFile("computers_updated.txt");
                    std::cout << "Updated inventory saved." << std::endl;
                    break;
                }
                else{
                    std::cout << "Changes not saved." << std::endl;
                    break;
                }
            }
            case 8:{ //Delete computer
                std::string idDel;
                std::cout << "Enter ID of computer to delete: ";
                std::getline(std::cin, idDel);
                store.deleteComputer(idDel);

                char saveChDel;
                std::cout << "Do you want to save the updated inventory? (y/n): ";
                std::cin >> saveChDel;
                clearCin();
                if (saveChDel == 'y' || saveChDel == 'Y'){
                    store.saveToFile("computers_updated.txt");
                    std::cout << "Updated inventory saved." << std::endl;
                    break;
                }
                else{
                    std::cout << "Changes not saved." << std::endl;
                    break;
                }
            }
            case 9:{ //Save inventory to file
                store.saveToFile("computers_updated.txt");
                break;
            }
            case 0:{ //Exit
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default:{ //Invalid choice
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }

    } 
    while (choice != 0);
    return 0;
}



/* TESTING
//open and load
std::cout << "--- Loading inventory from file ---" << std::endl;
store.loadFromFile("computers.txt");

//now display
std::cout << "--- Displaying inventory ---" << std::endl;
store.displayInventory();

//Update inventory
std::cout << "--- Updating inventory ---" << std::endl;
store.saveToFile("computers_updated.txt");

std::cout << "Complete." << std::endl;
return 0;
*/
