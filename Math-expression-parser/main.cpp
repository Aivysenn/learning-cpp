#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    // --- 1. Operator Priority Database ---
    // Higher number means higher execution priority
    map<char, int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;

    cout << "--- Welcome to the Smart Math Parser! ---\n";
    cout << "Enter an expression (e.g., '2 * 3 + 10 / 2'):\n";

    string input;
    getline(cin, input);

    // Dynamic buffers for tokenized elements
    vector<double> numbers;
    vector<char> ops;

    stringstream ss(input);
    double num;
    char op;

    // --- 2. Lexical Parsing Phase ---
    // Extract numbers and operators sequentially from the stream
    if (ss >> num) {
        numbers.push_back(num);
    }

    while (ss >> op >> num) {
        if (!priority.count(op)) {
            cout << "Error: Invalid operator '" << op << "'\n";
            return 1;
        }
        ops.push_back(op);
        numbers.push_back(num);
    }

    // --- 3. High-Priority Processing (* and /) ---
    vector<double> finalNumbers;
    vector<char> finalOps;
    
    if (!numbers.empty()) {
        finalNumbers.push_back(numbers[0]);
    }

    for (size_t i = 0; i < ops.size(); ++i) {
        char currentOp = ops[i];
        double nextNum = numbers[i + 1];

        if (priority[currentOp] == 2) {
            // Execute multiplication or division immediately on the last cached number
            double lastNum = finalNumbers.back();
            finalNumbers.pop_back();

            if (currentOp == '*') {
                finalNumbers.push_back(lastNum * nextNum);
            } else if (currentOp == '/') {
                if (nextNum == 0) {
                    cout << "Error: Division by zero!\n";
                    return 1;
                }
                finalNumbers.push_back(lastNum / nextNum);
            }
        } else {
            // Postpone low-priority operations (+ and -)
            finalOps.push_back(currentOp);
            finalNumbers.push_back(nextNum);
        }
    }

    // --- 4. Low-Priority Processing (+ and -) ---
    double result = finalNumbers[0];
    for (size_t i = 0; i < finalOps.size(); ++i) {
        char currentOp = finalOps[i];
        double nextNum = finalNumbers[i + 1];

        if (currentOp == '+') result += nextNum;
        if (currentOp == '-') result -= nextNum;
    }

    // --- 5. Output Result ---
    cout << "\nExecution Result: " << result << "\n";

    return 0;
}