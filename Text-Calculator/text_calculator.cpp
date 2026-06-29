#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // --- 1. Maps to convert words into numbers and operations ---
    map<string, int> numbers;
    numbers["zero"] = 0;
    numbers["one"] = 1;
    numbers["two"] = 2;
    numbers["three"] = 3;
    numbers["four"] = 4;
    numbers["five"] = 5;
    numbers["six"] = 6;
    numbers["seven"] = 7;
    numbers["eight"] = 8;
    numbers["nine"] = 9;
    numbers["ten"] = 10;

    map<string, char> operations;
    operations["plus"] = '+';
    operations["minus"] = '-';

    // --- 2. Reverse map to output the result in words (from 0 to 20) ---
    map<int, string> textNumbers;
    textNumbers[0] = "zero";   textNumbers[1] = "one";     textNumbers[2] = "two";
    textNumbers[3] = "three";  textNumbers[4] = "four";    textNumbers[5] = "five";
    textNumbers[6] = "six";    textNumbers[7] = "seven";   textNumbers[8] = "eight";
    textNumbers[9] = "nine";   textNumbers[10] = "ten";    textNumbers[11] = "eleven";
    textNumbers[12] = "twelve"; textNumbers[13] = "thirteen"; textNumbers[14] = "fourteen";
    textNumbers[15] = "fifteen"; textNumbers[16] = "sixteen"; textNumbers[17] = "seventeen";
    textNumbers[18] = "eighteen"; textNumbers[19] = "nineteen"; textNumbers[20] = "twenty";

    // --- 3. Input text expression ---
    string input;
    cout << "Enter expression (e.g., 'five plus three minus two'):\n";
    getline(cin, input);

    // Split the string into individual words using stringstream
    stringstream ss(input);
    string word;
    
    int result = 0;
    char currentOp = '+'; // By default, we add the first number to zero
    bool hasError = false;

    // --- 4. Parsing and calculation ---
    while (ss >> word) {
        if (numbers.count(word)) {
            int currentNum = numbers[word];
            
            // Execute the previously stored operation
            if (currentOp == '+') {
                result += currentNum;
            } else if (currentOp == '-') {
                result -= currentNum;
            }
        } 
        else if (operations.count(word)) {
            currentOp = operations[word]; // Remember the operation for the next number
        } 
        else {
            cout << "Error: Unknown word '" << word << "'\n";
            hasError = true;
            break;
        }
    }

    // --- 5. Output the result ---
    if (!hasError) {
        cout << "\nMath result: " << result << "\n";

        // Try to translate the result back into a word
        if (textNumbers.count(result)) {
            cout << "In words: " << textNumbers[result] << "\n";
        } else if (result < 0) {
            int absValue = abs(result);
            if (textNumbers.count(absValue)) {
                cout << "In words: minus " << textNumbers[absValue] << "\n";
            }
        } else {
            cout << "In words: (Result is too big to translate)\n";
        }
    }

    return 0;
}