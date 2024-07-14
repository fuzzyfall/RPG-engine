#include "../headers/EditorMenuFunctions.h"
#include "../headers/MainMenuFunctions.h"
#include "../headers/OptionsMenuFunctions.h"
#include "../headers/Structures.h"
#include <iostream>
#include <limits>
#include <vector>

void ShowEditorMenu(Game& game) {
    bool exitEditor = false;
    while (!exitEditor) {
        std::cout << "\n=== Editor Menu ===\n";
        std::cout << "1. Create New Zone\n";
        std::cout << "2. Edit Existing Zone\n";
        std::cout << "3. Delete Existing Zone\n";
        std::cout << "4. Exit Editor\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                CreateNewZone(game, game.zones);  // Assuming game.zones is a vector<Zone>& in Game struct/class
                break;
            case 2:
                EditExistingZone(game, game.zones); // Pass game and zones to edit an existing zone
                break;
            case 3:
                DeleteExistingZone(game);  // Delete a zone from the game
                break;
            case 4:
                exitEditor = true;  // Exit the editor menu
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void CreateNewZone(Game& game, std::vector<Zone>& zones) {
    Zone newZone;

    // Prompt and read the name of the new zone
    std::cout << "Enter the name of the new zone: ";
    std::getline(std::cin, newZone.name);

    // Prompt and read if the zone is peaceful (1 for yes, 0 for no)
    std::cout << "Is this zone peaceful? (1 for yes, 0 for no): ";
    std::cin >> newZone.isPeaceful;

    // Prompt and read if it's a starting zone (1 for yes, 0 for no)
    std::cout << "Is this a starting zone? (1 for yes, 0 for no): ";
    std::cin >> newZone.isStartingZone;

    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Manage options for the new zone
    OptionsMenu(newZone); // Pass the newZone to OptionsMenu

    // Add the new zone to the zones vector
    zones.push_back(newZone);

    // After creating a new zone, go to the options menu
    OptionsMenu(zones.back());
}

void EditExistingZone(Game& game, std::vector<Zone>& zones) {
    if (zones.empty()) {
        std::cout << "No zones available to edit.\n";
        return;
    }

    std::cout << "\n=== Edit Zone ===\n";
    for (size_t i = 0; i < zones.size(); ++i) {
        std::cout << i + 1 << ". " << zones[i].name << "\n";
    }

    int choice;
    std::cout << "Enter the index of the zone to edit (1-" << zones.size() << "): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice <= 0 || choice > zones.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    Zone& zoneToEdit = zones[choice - 1];

    // Manage options for the existing zone
    OptionsMenu(zoneToEdit);
}

void DeleteExistingZone(Game& game) {
    if (game.zones.empty()) {
        cout << "No zones available to delete.\n";
        return;
    }

    cout << "\n=== Available Zones ===\n";
    for (size_t i = 0; i < game.zones.size(); ++i) {
        cout << i + 1 << ". " << game.zones[i].name << "\n";
    }

    int choice;
    cout << "Enter the index of the zone to delete (1-" << game.zones.size() << "): ";
    cin >> choice;

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice <= 0 || choice > game.zones.size()) {
        cout << "Invalid index.\n";
        return;
    }

    cout << "Deleting zone '" << game.zones[choice - 1].name << "'.\n";
    game.zones.erase(game.zones.begin() + choice - 1);
}
