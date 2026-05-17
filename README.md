# Text-Based RPG Combat System (C++)

A lightweight, modular console-based battle simulator developed in C++. This project demonstrates foundational game development concepts, structured programming principles, and efficient memory management using references.

## 🚀 Key Features
* **Turn-Based Mechanics:** Interactive loop tracking player actions and enemy counter-attacks.
* **Modular Codebase:** Refactored into clean, reusable functions (`healPlayer`, `dealDamage`) to enforce the **DRY (Don't Repeat Yourself)** principle.
* **Memory Optimization:** Uses pass-by-reference (`int &`) parameters to directly manipulate variable states in memory without unnecessary copying.
* **Dynamic Event Triggers:** Integrated luck/lifesteal mechanic that restores HP on successful attacks.

## 🛠️ Concepts Applied
* Loops (`while`) and Conditional Statements (`if-else`)
* Standard Input/Output (`std::cin`, `std::cout`)
* Functions with `void` return types
* References and Memory Management (`&` operator)

## 🎮 How to Play
1. Compile the `boss_battle_remake.cpp` file using any C++ compiler (e.g., `g++ boss_battle_remake.cpp -o game`).
2. Run the executable.
3. Enter `1` to strike the boss and test your luck!
