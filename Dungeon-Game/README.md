# How the Dungeon Crawler Works

This is a text-based procedural dungeon crawler game that dynamically manages world states, room transitions, and turn-based combat using relational structures.

### 1. World Mapping Phase

- **Relational Room Tracking:** Uses a nested `std::map<string, Room>` configuration where the room name acts as a unique ID to retrieve localized objects, descriptions, and dynamic item spawns.
- **Node-Based Navigation:** Each structural room holds its own `std::map<string, string> exits` subsystem, linking directional navigation commands (e.g., `"north"`, `"east"`) directly to adjacent room keys.
- **State Serialization:** Tracks structural changes in real-time — once an item is picked up (`take`) or an enemy is defeated (`attack`), the room variables update permanently.

**Example:**

- **Input:** `go north`
- **Process:** Validates if an enemy is alive —> checks `room.exits["north"]` —> fetches the target string ID (`"Corridor"`) —> moves player pointer.
- **Output:** `Walking to the north... You entered a long, narrow corridor covered in spiderwebs.`

—

### 2. State Management & Combat Cycles

- **Dynamic Tokenization:** Uses `std::stringstream` buffer extraction to safely isolate gameplay command verbs from their associated direct-object targets.
- **Turn-Based Scaling:** Combat triggers calculations that subtract player damage from enemy health, scaling enemy reaction updates via a randomized turn algorithm (`rand()`).
- **Conditional Victory Triggers:** Tracks inventory collections and specific room clears to automatically execute conditional winning states.

—

# What I Learned from This Project

- **Advanced Structures:** Gained hands-on experience nesting maps inside custom `struct` architectures to form advanced complex databases.
- **Game State Logic:** Handled state-based control logic loops, preventing players from leaving a room while actively engaged with hostile NPC entities.
