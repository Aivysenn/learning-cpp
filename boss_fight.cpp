#include <iostream>
using namespace std;

// Function to heal the player using a reference to modify the original variable
void healPlayer(int &playerHealth, int hpPlus) {
    playerHealth += hpPlus;
}

// Universal function to deal damage to any target
void dealDamage(int &targetHealth, int damage) {
    targetHealth -= damage;
}

int main() {
    // Player stats
    int playerHealth = 100;
    int playerDamage = 20;
    int hpPlus = 5;
    
    // Boss stats
    int bossHealth = 100;
    int bossDamage = 15;
    
    int action;

    // Turn-based combat loop: runs while both are alive
    while (playerHealth > 0 && bossHealth > 0) {
        cout << "Player's turn. Press 1 to attack: \n";
        cin >> action;
        
        if (action == 1) {
            // Player attacks the boss
            dealDamage(bossHealth, playerDamage); 
            cout << "You struck the boss! Remaining boss HP: " << bossHealth << "\n";
            
            // Lifesteal/Luck mechanic triggers
            healPlayer(playerHealth, hpPlus);
            cout << "Lucky! Your HP increased by 5. Current HP: " << playerHealth << "\n";
            
            // Check if the boss is defeated
            if (bossHealth <= 0) {
                cout << "Victory! The boss has been defeated!\n";
                break; 
            }
            
            // Boss counter-attacks the player
            dealDamage(playerHealth, bossDamage); 
            cout << "The boss countered! Your remaining HP: " << playerHealth << "\n\n";
            
            // Check if the player died
            if (playerHealth <= 0) {
                cout << "You died in battle... Game Over.\n";
            }
        } else {
            cout << "Invalid action! Please try again.\n\n";
        }
    }
   
    return 0;
}