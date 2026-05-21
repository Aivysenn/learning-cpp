#include <iostream>
#include <limits> // Required for clearing the cin buffer

// Function to validate numerical input (prevents infinite loops on letters)
int getValidatedInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cin.clear(); // Reset the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
        std::cout << "Invalid input! Please enter a number: ";
    }
    return input;
}

int main() {
    int balance = 500;  // Starting balance
    bool isRunning = true;

    std::cout << "Welcome to the Mini-Bank!\n";

    while (isRunning) {  
        std::cout << "\nSelect an action:\n"
                  << "1 - Check balance\n"
                  << "2 - Deposit money\n"
                  << "3 - Withdraw money\n"
                  << "4 - Exit\n"
                  << "Your choice: ";
        
        int choice = getValidatedInput();

        switch (choice) {
            case 1:
                std::cout << "Your current balance is: $" << balance << "\n";
                break;

            case 2: {
                std::cout << "Enter deposit amount: $";
                int deposit = getValidatedInput();

                if (deposit > 0) {
                    balance += deposit;
                    std::cout << "Balance updated. New balance: $" << balance << "\n";
                } else {
                    std::cout << "Error: Cannot deposit a negative amount or zero!\n";
                }
                break;
            }

            case 3: {
                std::cout << "Enter withdrawal amount: $";
                int withdrawal = getValidatedInput();

                if (withdrawal > 0 && withdrawal <= balance) {
                    balance -= withdrawal;
                    std::cout << "Successfully withdrew $" << withdrawal << ". New balance: $" << balance << "\n";
                } else if (withdrawal > balance) {
                    std::cout << "Error: Insufficient funds!\n";
                } else {
                    std::cout << "Error: Cannot withdraw a negative amount or zero!\n";
                }
                break;
            }

            case 4:
                std::cout << "Thank you for using Mini-Bank! Goodbye!\n";
                isRunning = false; // Elegant exit from the loop
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}