# How the RPG Inventory Works

This is a text-based inventory and status system for a conceptual CLI RPG game. It demonstrates double-mapped associative structures and split-buffer string tokenization.

### 1. State Mapping Phase

- **Inventory Tracking:** Uses `std::map<string, int>` to map item names to their current quantity in the player's backpack.
- **Dynamic Action Parsing:** Using `std::stringstream`, the interface extracts the primary action verb (`"pick"`, `"use"`) and binds it to the target item argument.
- **Attribute Modifiers:** Separate maps store value increments for healing impacts or attack strength scales.

**Example:**

- **Input:** `use potion`
- **Process:** Checks if `inventory["potion"] > 0` —> subtracts 1 —> reads `healEffects["potion"]` (+40) —> applies to `HP`.
- **Output:** `You used potion. Healed for 40 HP.`

—

# What I Learned from This Project

- **Data Structures (`std::map`):** Practiced managing multi-layered maps to link game objects with state properties.
- **State Control Loops:** Designed a continuous validation cycle handling edge cases (e.g., using items you don't own, or healing past max health capacity).
