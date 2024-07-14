#include "../headers/EditorMenuFunctions.h"
#include "../headers/MainMenuFunctions.h"
#include "../headers/OptionsMenuFunctions.h"
#include "../headers/Structures.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void OptionsMenu(Zone& zone) {
    bool exitOptions = false;
    while (!exitOptions) {
        std::cout << "\n=== Manage Options ===\n";
        std::cout << "1. Create Option\n";
        std::cout << "2. Edit Option\n";
        std::cout << "3. Delete Option\n";
        std::cout << "4. Exit Manage Options\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                CreateOption(zone);
                break;
            case 2:
                EditOption(zone);
                break;
            case 3:
                DeleteOption(zone);
                break;
            case 4:
                exitOptions = true;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void CreateOption(Zone& zone) {
    Option newOption;
    std::cout << "What do you want this option to say? ";
    std::getline(std::cin, newOption.name);
    std::cout << "Is this a traveler option? (1 for yes, 0 for no): ";
    std::cin >> newOption.isTraveler;
    if (newOption.isTraveler) {
        std::cout << "Enter linked zone index: ";
        std::cin >> newOption.linkedZone;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    zone.options.push_back(newOption);
}

void EditOption(Zone& zone) {
    if (zone.options.empty()) {
        std::cout << "No options available to edit.\n";
        return;
    }

    std::cout << "\n=== Edit Option ===\n";
    for (size_t i = 0; i < zone.options.size(); ++i) {
        std::cout << i + 1 << ". " << zone.options[i].name << "\n";
    }

    int choice;
    std::cout << "Enter the index of the option to edit (1-" << zone.options.size() << "): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice <= 0 || choice > zone.options.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    Option& optionToEdit = zone.options[choice - 1];
    std::cout << "What do you want this option to say? ";
    std::getline(std::cin, optionToEdit.name);
    std::cout << "Is this a traveler option? (1 for yes, 0 for no): ";
    std::cin >> optionToEdit.isTraveler;
    if (optionToEdit.isTraveler) {
        std::cout << "Enter linked zone index: ";
        std::cin >> optionToEdit.linkedZone;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
}

void DeleteOption(Zone& zone) {
    if (zone.options.empty()) {
        std::cout << "No options available to delete.\n";
        return;
    }

    std::cout << "\n=== Delete Option ===\n";
    for (size_t i = 0; i < zone.options.size(); ++i) {
        std::cout << i + 1 << ". " << zone.options[i].name << "\n";
    }

    int choice;
    std::cout << "Enter the index of the option to delete (1-" << zone.options.size() << "): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice <= 0 || choice > zone.options.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    zone.options.erase(zone.options.begin() + choice - 1);
}