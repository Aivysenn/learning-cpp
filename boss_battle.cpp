#include <iostream>
using namespace std;

int main() {
    int playerHealth = 100;
    int playerDamage = 20;
    
    int bossHealth = 100;
    int bossDamage = 15;
    
    int answer;
    
    // The loop runs while both player and boss are alive
    while (playerHealth > 0 && bossHealth > 0) {
        cout << "Your turn! Press 1 to attack: \n";
        cin >> answer; // Getting player's choice
        
        if (answer == 1) {
            bossHealth -= playerDamage; // Dealing damage to the boss
            cout << "You struck the boss! Boss HP left: " << bossHealth << "\n";
            
            // Check if the boss died from the attack
            if (bossHealth <= 0) {
                cout << "Victory! The boss has been defeated!\n";
                break; // Exit the loop
            }
            
            playerHealth -= bossDamage; // Boss counters the attack
            cout << "The boss countered! Your HP left: " << playerHealth << "\n\n";
            
            if (playerHealth <= 0) {
                cout << "Game Over... You died in battle.\n";
            }
        } else {
            cout << "Invalid action! Please try again.\n\n";
        }
    }
   
    return 0;
}