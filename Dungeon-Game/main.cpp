#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure to hold dungeon room data
struct Room {
    string description;
    string item;
    string enemy;
    int enemyHp;
    map<string, string> exits; // direction -> next room name
};

int main() {
    srand(time(0));

    // Player stats
    int playerHp = 100;
    int playerDamage = 25;
    vector<string> inventory;

    // --- 1. Dungeon Map Database ---
    map<string, Room> dungeon;

    // Creating the starting room
    dungeon["Entrance"].description = "a cold stone hall with flickering torches.";
    dungeon["Entrance"].item = "shield";
    dungeon["Entrance"].enemy = "none";
    dungeon["Entrance"].exits["north"] = "Corridor";

    // Creating the corridor
    dungeon["Corridor"].description = "a long, narrow corridor covered in spiderwebs.";
    dungeon["Corridor"].item = "none";
    dungeon["Corridor"].enemy = "Giant_Spider";
    dungeon["Corridor"].enemyHp = 30;
    dungeon["Corridor"].exits["south"] = "Entrance";
    dungeon["Corridor"].exits["east"] = "Treasure_Room";

    // Creating the treasure room
    dungeon["Treasure_Room"].description = "a golden chamber guarded by a scary shadow.";
    dungeon["Treasure_Room"].item = "Magic_Sword";
    dungeon["Treasure_Room"].enemy = "Shadow_Knight";
    dungeon["Treasure_Room"].enemyHp = 60;
    dungeon["Treasure_Room"].exits["west"] = "Corridor";

    // Current player position
    string currentRoom = "Entrance";

    cout << "--- Welcome to the Text Dungeon Crawler! ---\n";
    cout << "Commands: 'look', 'go <direction>', 'take', 'attack', 'status', 'exit'\n\n";

    // Initial look at the first room
    cout << "You are in " << dungeon[currentRoom].description << "\n";

    string input;
    while (playerHp > 0) {
        cout << "> ";
        getline(cin, input);

        stringstream ss(input);
        string command, argument;
        ss >> command >> argument;

        if (command == "exit") {
            cout << "You fled the dungeon. Game Over.\n";
            break;
        }

        // --- 2. LOOK Command ---
        else if (command == "look") {
            Room &room = dungeon[currentRoom];
            cout << "You see " << room.description << "\n";
            
            if (room.enemy != "none" && room.enemyHp > 0) {
                cout << "⚠️ A wild [" << room.enemy << "] (HP: " << room.enemyHp << ") blocks your path!\n";
            }
            if (room.item != "none") {
                cout << "💎 There is a [" << room.item << "] on the floor.\n";
            }
            
            cout << "Exits: ";
            for (auto const& [direction, nextRoom] : room.exits) {
                cout << direction << " ";
            }
            cout << "\n";
        }

        // --- 3. GO Command ---
        else if (command == "go") {
            Room &room = dungeon[currentRoom];
            
            // Block movement if enemy is alive
            if (room.enemy != "none" && room.enemyHp > 0) {
                cout << "You cannot escape! The " << room.enemy << " attacks you if you try to run!\n";
                continue;
            }

            if (room.exits.count(argument)) {
                currentRoom = room.exits[argument];
                cout << "\nWalking to the " << argument << "...\n";
                cout << "You entered " << dungeon[currentRoom].description << "\n";
            } else {
                cout << "Error: You can't go '" << argument << "' from here.\n";
            }
        }

        // --- 4. TAKE Command ---
        else if (command == "take") {
            Room &room = dungeon[currentRoom];
            if (room.item != "none") {
                cout << "You picked up the " << room.item << "!\n";
                inventory.push_back(room.item);
                
                // Scale damage if the sword is acquired
                if (room.item == "Magic_Sword") {
                    playerDamage += 20;
                    cout << "⚔️ Your Attack Power increased!\n";
                }
                room.item = "none"; // Remove item from the room
            } else {
                cout << "There is nothing to take here.\n";
            }
        }

        // --- 5. ATTACK Command ---
        else if (command == "attack") {
            Room &room = dungeon[currentRoom];
            if (room.enemy == "none" || room.enemyHp <= 0) {
                cout << "There is no one here to attack.\n";
                continue;
            }

            // Player turn
            room.enemyHp -= playerDamage;
            cout << "You hit the " << room.enemy << " for " << playerDamage << " damage!\n";

            // Check if enemy died
            if (room.enemyHp <= 0) {
                cout << "🎉 You defeated the " << room.enemy << "!\n";
                if (currentRoom == "Treasure_Room") {
                    cout << "🏆 Congratulations! You cleared the dungeon and won the game!\n";
                    break;
                }
                continue;
            }

            // Enemy turn (randomized damage scale)
            int enemyDamage = rand() % 15 + 5;
            playerHp -= enemyDamage;
            cout << "The " << room.enemy << " strikes back and deals " << enemyDamage << " damage to you!\n";

            if (playerHp <= 0) {
                cout << "💀 You died in the dungeon... Game Over.\n";
            }
        }

        // --- 6. STATUS Command ---
        else if (command == "status") {
            cout << "\n=== HERO STATUS ===\n";
            cout << "HP: " << playerHp << "/100\n";
            cout << "Damage: " << playerDamage << "\n";
            cout << "Inventory: ";
            if (inventory.empty()) cout << "(empty)";
            for (string i : inventory) cout << "[" << i << "] ";
            cout << "\n===================\n\n";
        }

        else {
            cout << "Unknown command. Available: look, go <dir>, take, attack, status, exit\n";
        }
    }

    return 0;
}