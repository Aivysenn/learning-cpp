#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Generates a random symbol to use as a separator in the cipher
char randomSymbol() {
    string symbols = ";!@#$%^&*";
    return symbols[rand() % symbols.size()];
}

int main() {
    srand(time(0)); // Initialize random number generator

    // --- 1. Cipher Map: character -> unique number ---
    map<char, int> alphabet = {
        {"a", 309}, {"b", 103}, {"c", 0},   {"d", 71},  {"e", 703},
        {"f", 99},  {"g", 301}, {"h", 32},  {"i", 401}, {"j", 660},
        {"k", 50},  {"l", 800}, {"m", 337}, {"n", 90},  {"o", 210},
        {"p", 77},  {"q", 708}, {"r", 420}, {"s", 11},  {"t", 201},
        {"u", 322}, {"v", 89},  {"w", 57},  {"x", 530}, {"y", 76},  {"z", 105}
    };

    // --- 2. Reverse Map for decryption ---
    map<int, char> reverseAlphabet;
    for (auto pair : alphabet) {
        reverseAlphabet[pair.second] = pair.first;
    }

    // --- 3. User Input ---
    string text;
    cout << "Enter text to encrypt: ";
    getline(cin, text);

    // --- 4. Encryption Process ---
    string encrypted;
    for (char c : text) {
        if (alphabet.count(c)) {
            encrypted += to_string(alphabet[c]);
            encrypted += randomSymbol(); // Insert random separator after the number
        } else {
            encrypted += c; // Keep spaces and punctuation as they are
        }
    }

    cout << "\nEncrypted text: " << encrypted << "\n";

    // --- 5. Decryption Prompt ---
    string answer;
    cout << "\nDo you want to decrypt your text back? (yes/no): ";
    getline(cin, answer);

    // Fixed logical OR operators
    if (answer == "yes" || answer == "Yes" || answer == "y" || answer == "Y") {
        string decrypted;
        string tempNumber;

        for (char ch : encrypted) {
            if (isdigit(ch)) {
                tempNumber += ch; // Build the number digit by digit
            } else {
                if (!tempNumber.empty()) {
                    int num = stoi(tempNumber);
                    if (reverseAlphabet.count(num))
                        decrypted += reverseAlphabet[num];
                    else
                        decrypted += "?";
                    tempNumber = "";
                }

                if (isspace(ch)) {
                    decrypted += ch; // Keep spaces
                } else if (string(";!@#$%^&*").find(ch) == string::npos) {
                    decrypted += ch; // Keep other regular characters
                }
                // Random symbols used as separators are ignored here
            }
        }

        // Check for the final number in the string
        if (!tempNumber.empty()) {
            int num = stoi(tempNumber);
            if (reverseAlphabet.count(num))
                decrypted += reverseAlphabet[num];
            else
                decrypted += "?";
        }

        cout << "Decrypted text: " << decrypted << "\n";
    } else {
        cout << "Goodbye!\n";
    }

    return 0;
}