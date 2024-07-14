#include "../headers/EditorMenuFunctions.h"
#include "../headers/MainMenuFunctions.h"
#include "../headers/OptionsMenuFunctions.h"
#include "../headers/Structures.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void MainMenu() {
    vector<Game> games;

    bool quit = false;
    while (!quit) {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Start New Save File\n";
        cout << "2. Load Save File\n";
        cout << "3. Create New Game\n";
        cout << "4. Edit Game\n";
        cout << "5. Delete Save File\n";
        cout << "6. Delete Game\n";
        cout << "7. Quit Program\n";
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                StartNewSaveFile(games);
                break;
            case 2:
                LoadSaveFile(games);
                break;
            case 3:
                CreateNewGame(games);
                break;
            case 4:
                EditGame(games);
                break;
            case 5:
                DeleteSaveFile(games);
                break;
            case 6:
                DeleteGame(games);
                break;
            case 7:
                QuitProgram();
                quit = true;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
}

void StartNewSaveFile(std::vector<Game>& games) {
    Game newGame;
    std::cout << "Enter the name of the new game: ";
    std::getline(std::cin, newGame.name);
    std::cout << "\nCreating a new game '" << newGame.name << "'...\n";

    games.push_back(newGame);
    LoadAndPlayGame(games); // Pass the vector of games to LoadAndPlayGame
}

void LoadSaveFile(std::vector<Game>& games) {
    // Simulated logic for loading a game
    std::cout << "Loading a saved game...\n";

    // Simulated game selection
    if (games.empty()) {
        std::cout << "No saved games available.\n";
        return;
    }

    // Select a game to load
    int choice;
    std::cout << "Select a game to load:\n";
    for (size_t i = 0; i < games.size(); ++i) {
        std::cout << i + 1 << ". " << games[i].name << "\n";
    }
    std::cout << "Enter the number of the game to load: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice < 1 || choice > games.size()) {
        std::cout << "Invalid choice.\n";
        return;
    }

    Game& game = games[choice - 1];
    std::vector<Game> gameVector = {game};  // Create a vector with a single game
    LoadAndPlayGame(gameVector); // Pass the vector of games to LoadAndPlayGame
}

void LoadAndPlayGame(std::vector<Game>& games) {
    std::cout << "\nLoading and playing a game...\n";

    // Display available games
    std::cout << "Available Games:\n";
    for (size_t i = 0; i < games.size(); ++i) {
        std::cout << i + 1 << ". " << games[i].name << "\n";
    }

    // Choose a game
    int choice;
    std::cout << "Enter the number of the game you want to play: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

    if (choice < 1 || choice > games.size()) {
        std::cout << "Invalid choice.\n";
        return;
    }

    Game& game = games[choice - 1];

    // Implement gameplay logic here
    // Example: Starting the game loop
    bool quitGame = false;
    while (!quitGame) {
        // Game loop logic
        std::cout << "\nGameplay loop placeholder.\n";

        // Example: Implement game logic, interactions, etc.

        // Example: Quit condition
        // For example, a quit option could be implemented as:
        // quitGame = true; // when the player decides to quit
    }

    std::cout << "Exiting the game.\n";
}

void CreateNewGame(vector<Game>& games) {
    Game newGame;
    cout << "Enter the name of the new game: ";
    getline(cin, newGame.name);
    cout << "\nCreating a new game '" << newGame.name << "'...\n";

    games.push_back(newGame);
    ShowEditorMenu(games.back()); // Pass the newly created game to the editor menu

    // After ShowEditorMenu, do not automatically return to the main menu loop
}

void EditGame(vector<Game>& games) {
    if (games.empty()) {
        cout << "No games available to edit.\n";
        return;
    }
    
    cout << "\n=== Available Games ===\n";
    for (size_t i = 0; i < games.size(); ++i) {
        cout << i + 1 << ". " << games[i].name << "\n";
    }
    
    int choice;
    cout << "Enter the index of the game to edit (1-" << games.size() << "): ";
    cin >> choice;
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (choice <= 0 || choice > games.size()) {
        cout << "Invalid index.\n";
        return;
    }
    
    ShowEditorMenu(games[choice - 1]);

    // After ShowEditorMenu, do not automatically return to the main menu loop
}

void DeleteSaveFile(vector<Game>& games) {
    if (games.empty()) {
        cout << "No save files available to delete.\n";
        return;
    }

    cout << "\n=== Available Save Files ===\n";
    for (size_t i = 0; i < games.size(); ++i) {
        cout << i + 1 << ". " << games[i].name << "\n";
    }

    int choice;
    cout << "Enter the index of the save file to delete (1-" << games.size() << "): ";
    cin >> choice;

    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice <= 0 || choice > games.size()) {
        cout << "Invalid index.\n";
        return;
    }

    cout << "\nDeleting save file for game '" << games[choice - 1].name << "'...\n";
    // Code to delete the save file goes here

    cout << "Save file deleted successfully.\n";
}

void DeleteGame(vector<Game>& games) {
    if (games.empty()) {
        cout << "No games available to delete.\n";
        return;
    }
    
    cout << "\n=== Available Games ===\n";
    for (size_t i = 0; i < games.size(); ++i) {
        cout << i + 1 << ". " << games[i].name << "\n";
    }
    
    int choice;
    cout << "Enter the index of the game to delete (1-" << games.size() << "): ";
    cin >> choice;
    
    // Clear input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (choice <= 0 || choice > games.size()) {
        cout << "Invalid index.\n";
        return;
    }
    
    cout << "\nDeleting game '" << games[choice - 1].name << "'...\n";
    games.erase(games.begin() + choice - 1);
    cout << "Game deleted successfully.\n";
}

void QuitProgram() {
    cout << "Exiting program.\n";
}
