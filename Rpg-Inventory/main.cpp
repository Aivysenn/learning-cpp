#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Initial player stats
    int hp = 50;
    int maxHp = 100;
    int attack = 10;

    // --- 1. Item Maps ---
    // Inventory: item name -> quantity
    map<string, int> inventory;
    inventory["potion"] = 2;   // healing potion
    inventory["apple"] = 1;    // apple
    inventory["sword"] = 0;    // sword (not acquired yet)

    // Item effects: item name -> stat increase amount
    map<string, int> healEffects;
    healEffects["potion"] = 40;
    healEffects["apple"] = 10;

    map<string, int> attackEffects;
    attackEffects["sword"] = 15;

    cout << "--- Welcome to the Text RPG Inventory System! ---\n";
    cout << "Commands: 'status', 'pick <item>', 'use <item>', 'exit'\n\n";

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        // Split input into command and argument (e.g., "use" and "potion")
        stringstream ss(input);
        string command, item;
        ss >> command >> item;

        // Exit the game
        if (command == "exit") {
            cout << "Goodbye, adventurer!\n";
            break;
        }

        // --- 2. STATUS Command ---
        else if (command == "status") {
            cout << "\n=== PLAYER STATUS ===\n";
            cout << "HP: " << hp << "/" << maxHp << "\n";
            cout << "Attack Power: " << attack << "\n";
            cout << "--- Inventory ---\n";
            
            bool isEmpty = true;
            for (auto const& [name, count] : inventory) {
                if (count > 0) {
                    cout << "- " << name << ": " << count << "\n";
                    isEmpty = false;
                }
            }
            if (isEmpty) {
                cout << "(your backpack is empty)\n";
            }
            cout << "=====================\n\n";
        }

        // --- 3. PICK Command (pick up an item) ---
        else if (command == "pick") {
            if (item.empty()) {
                cout << "Error: What do you want to pick up? (e.g., 'pick sword')\n";
                continue;
            }

            // Check if the item exists in the game data
            if (inventory.count(item)) {
                inventory[item]++;
                cout << "You picked up a " << item << "!\n";
            } else {
                cout << "Error: Unknown item '" << item << "'\n";
            }
        }

        // --- 4. USE Command (use an item) ---
        else if (command == "use") {
            if (item.empty()) {
                cout << "Error: What do you want to use? (e.g., 'use potion')\n";
                continue;
            }

            // Check if the item is in the inventory
            if (!inventory.count(item) || inventory[item] <= 0) {
                cout << "Error: You don't have '" << item << "' in your inventory.\n";
                continue;
            }

            // Logic for HEALING items
            if (healEffects.count(item)) {
                if (hp >= maxHp) {
                    cout << "Your health is already full!\n";
                } else {
                    hp = min(maxHp, hp + healEffects[item]);
                    inventory[item]--; // Consume the item
                    cout << "You used " << item << ". Healed for " << healEffects[item] << " HP.\n";
                }
            }
            // Logic for WEAPONS
            else if (attackEffects.count(item)) {
                attack += attackEffects[item];
                inventory[item]--; // Equipped (remove from backpack)
                cout << "You equipped " << item << "! Attack increased by " << attackEffects[item] << ".\n";
            } 
            else {
                cout << "Error: You can't use '" << item << "' right now.\n";
            }
        }

        // If command is invalid
        else {
            cout << "Error: Unknown command. Use 'status', 'pick', 'use', or 'exit'.\n";
        }
    }

    return 0;
}