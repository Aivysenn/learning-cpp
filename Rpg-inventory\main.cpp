#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Начальные характеристики игрока
    int hp = 50;
    int maxHp = 100;
    int attack = 10;

    // --- 1. Словари для предметов ---
    // Инвентарь: название предмета -> количество
    map<string, int> inventory;
    inventory["potion"] = 2;   // зелье лечения
    inventory["apple"] = 1;    // яблоко
    inventory["sword"] = 0;    // меч (пока нет)

    // Эффекты предметов: название -> сколько добавляет к характеристикам
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

        // Разделяем ввод на команду и аргумент (например, "use" и "potion")
        stringstream ss(input);
        string command, item;
        ss >> command >> item;

        // Выход из игры
        if (command == "exit") {
            cout << "Goodbye, adventurer!\n";
            break;
        }

        // --- 2. Команда STATUS ---
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

        // --- 3. Команда PICK (подобрать предмет) ---
        else if (command == "pick") {
            if (item.empty()) {
                cout << "Error: What do you want to pick up? (e.g., 'pick sword')\n";
                continue;
            }

            // Проверяем, существует ли вообще такой предмет в игре
            if (inventory.count(item)) {
                inventory[item]++;
                cout << "You picked up a " << item << "!\n";
            } else {
                cout << "Error: Unknown item '" << item << "'\n";
            }
        }

        // --- 4. Команда USE (использовать предмет) ---
        else if (command == "use") {
            if (item.empty()) {
                cout << "Error: What do you want to use? (e.g., 'use potion')\n";
                continue;
            }

            // Проверяем, есть ли предмет в инвентаре
            if (!inventory.count(item) || inventory[item] <= 0) {
                cout << "Error: You don't have '" << item << "' in your inventory.\n";
                continue;
            }

            // Логика для ХИЛЯЩИХ предметов
            if (healEffects.count(item)) {
                if (hp >= maxHp) {
                    cout << "Your health is already full!\n";
                } else {
                    hp = min(maxHp, hp + healEffects[item]);
                    inventory[item]--; // Тратим предмет
                    cout << "You used " << item << ". Healed for " << healEffects[item] << " HP.\n";
                }
            }
            // Логика для ОРУЖИЯ
            else if (attackEffects.count(item)) {
                attack += attackEffects[item];
                inventory[item]--; // Экипировали (убираем из сумки)
                cout << "You equipped " << item << "! Attack increased by " << attackEffects[item] << ".\n";
            } 
            else {
                cout << "Error: You can't use '" << item << "' right now.\n";
            }
        }

        // Если команда неизвестна
        else {
            cout << "Error: Unknown command. Use 'status', 'pick', 'use', or 'exit'.\n";
        }
    }

    return 0;
}