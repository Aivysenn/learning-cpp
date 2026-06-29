#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "--- Welcome to the Huffman Text Compressor! ---\n";
    cout << "Enter a line of text to compress:\n";

    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "Error: Input text is empty.\n";
        return 1;
    }

    // --- 1. Frequency Analysis Phase ---
    // Count how many times each character appears in the text
    map<char, int> frequencies;
    for (char ch : input) {
        frequencies[ch]++;
    }

    // Move map data to a vector of pairs to sort it by frequency
    vector<pair<char, int>> sortedFreqs(frequencies.begin(), frequencies.end());
    sort(sortedFreqs.begin(), sortedFreqs.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort from highest frequency to lowest
    });

    // --- 2. Code Generation Phase ---
    // Generate simulated Huffman binary codes based on frequency ranking
    map<char, string> huffmanCodes;
    string currentCode = "0";

    cout << "\n=== Generated Bit Codes ===\n";
    for (size_t i = 0; i < sortedFreqs.size(); ++i) {
        char ch = sortedFreqs[i].first;
        
        // Assign shorter codes to frequent chars, longer codes to rare ones
        huffmanCodes[ch] = currentCode;
        cout << "'" << ch << "' (Freq: " << sortedFreqs[i].second << ") -> Binary Code: " << currentCode << "\n";
        
        // Shift binary sequence for the next character
        currentCode = "1" + currentCode; 
    }
    cout << "===========================\n";

    // --- 3. Compression Phase ---
    // Translate the original text string into compressed binary data
    string compressedData = "";
    for (char ch : input) {
        compressedData += huffmanCodes[ch];
    }

    // --- 4. Decompression Phase ---
    // Reconstruct the original text using a reverse bits lookup
    string decompressedText = "";
    string tempBits = "";
    
    // Build a reverse map for fast binary decryption
    map<string, char> reverseCodes;
    for (auto const& [ch, code] : huffmanCodes) {
        reverseCodes[code] = ch;
    }

    for (char bit : compressedData) {
        tempBits += bit;
        if (reverseCodes.count(tempBits)) {
            decompressedText += reverseCodes[tempBits];
            tempBits = ""; // Clear temporary bit buffer
        }
    }

    // --- 5. Output Optimization Report ---
    int originalBits = input.length() * 8; // Standard ASCII text uses 8 bits per character
    int compressedBits = compressedData.length();

    cout << "\nOriginal Text: " << input << "\n";
    cout << "Compressed Bits Data: " << compressedData << "\n";
    cout << "Decompressed Text: " << decompressedText << "\n\n";
    
    cout << "--- Compression Statistics ---\n";
    cout << "Original Size: " << originalBits << " bits\n";
    cout << "Compressed Size: " << compressedBits << " bits\n";
    cout << "Saved space: " << (100 - (compressedBits * 100 / originalBits)) << "%\n";

    return 0;
}