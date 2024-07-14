#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <vector>

using namespace std;

// Forward declarations of other structs/classes
struct Zone;
struct Item;
struct NPC;
struct Merchant;
struct Option;

// Struct definitions for game entities
struct Zone {
    int number;
    string name;
    bool isPeaceful;
    bool isStartingZone;
    vector<Option> options;
    // Add more properties as needed
};

struct Option {
    string name;
    bool isTraveler;
    int linkedZone; // Index of the zone linked to this option (if traveler option)
    // Add more properties as needed
};

struct Item {
    string name;
    bool isWeapon;
    bool isArmor;
    bool isConsumable;
    int value;  // Value of the item
    // Add more properties as needed
};

struct NPC {
    string name;
    // Add more properties as needed
};

struct Merchant {
    string name;
    // Add more properties as needed
};

struct Game {
    string name;
    vector<Zone> zones;
    vector<Item> items;
    vector<NPC> npcs;
    vector<Merchant> merchants;
    // Add more properties as needed
};

#endif
