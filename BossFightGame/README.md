# C++ Turn-Based Boss Battle Engine

A lightweight, console-based turn-based combat system written in C++. This project demonstrates core game design mechanics and highlights efficient memory management using C++ references.

## Features
- **Turn-Based Combat Loop:** A continuous battle cycle that handles player inputs, actions, and conditional win/loss states dynamically.
- **Universal Damage System:** A modular function capable of processing damage to any entity (player or boss) without duplicating code.
- **Lifesteal/Luck Mechanic:** Automatically rewards the player with health recovery immediately after a successful strike.
- **State Validation:** Real-time health checks after every action to instantly trigger "Victory" or "Game Over" states.

## How the Combat System Works

The game runs a simulation of a tactical encounter using a structured execution flow:

1. **Player's Turn:** The game prompts the user for action. Pressing `1` triggers a strike against the boss.
2. **Damage Application:** The application passes the boss's health variable to the damage calculator using a **reference (`&`)**, directly reducing its value.
3. **Modifier Trigger:** Upon hitting the target, the dynamic healing routine triggers, injecting static HP back into the player's main health pool.
4. **Counter-Attack Phase:** If the boss survives the initial blow, it automatically executes a counter-attack script, passing the player's health through the same universal damage function.

---

## What I Learned from This Project

Building this combat simulation helped me transition from structural logic to modular code design and memory optimization:

- **Pass-by-Reference (`int &`):** This was a crucial milestone. I mastered how to pass variables to functions by reference instead of making value copies. This allows direct modifications to the original player and boss health pools, which is a foundational concept for game loop optimization.
- **Modular Function Design:** Instead of writing separate logic for the player taking damage and the boss taking damage, I engineered a single, reusable `dealDamage` function. This aligns with the DRY (Don't Repeat Yourself) programming principle.
- **Game Loop Execution Flow:** I gained practical experience managing complex, nested game states inside a `while` loop, utilizing conditional `break` statements to cleanly halt execution exactly when a character's HP hits zero.
- **Interactive Console State Management:** Handled standard input streams (`cin`) paired with defensive `else` routing to catch invalid user inputs without crashing the combat loop.
