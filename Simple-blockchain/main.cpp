#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure to represent a single block in our blockchain
struct Block {
    int blockIndex;
    string data;
    int nonce;         // The winning number found during mining
    int previousHash;  // Simulating connection to the previous block
};

int main() {
    srand(time(0));

    map<string, int> balances;
    balances["System"] = 1000000; // System pool for mining rewards
    balances["Satoshi"] = 100;

    vector<Block> blockchain;
    vector<string> pendingTransactions; // Buffer for unmined txs

    Block genesis;
    genesis.blockIndex = 0;
    genesis.data = "Genesis Block - System Start";
    genesis.nonce = 0;
    genesis.previousHash = 0;
    blockchain.push_back(genesis);

    cout << "--- Welcome to the Mini-Blockchain Console! ---\n";
    cout << "Commands: 'balance <user>', 'send <from> <to> <amount>', 'mine', 'chain', 'exit'\n\n";

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "exit") {
            cout << "Shutting down node. Goodbye!\n";
            break;
        }

        else if (command == "balance") {
            string user;
            ss >> user;
            if (user.empty()) {
                cout << "Error: Specify a wallet name.\n";
                continue;
            }
            cout << "Wallet [" << user << "] Balance: " << balances[user] << " coins\n";
        }

        else if (command == "send") {
            string fromUser, toUser;
            int amount;
            ss >> fromUser >> toUser >> amount;

            if (fromUser.empty() || toUser.empty() || amount <= 0) {
                cout << "Error: Invalid transaction syntax. Use: send <from> <to> <amount>\n";
                continue;
            }

            if (balances[fromUser] < amount) {
                cout << "Error: Insufficient funds in wallet [" << fromUser << "].\n";
                continue;
            }

            balances[fromUser] -= amount;
            balances[toUser] += amount;

            string txLog = fromUser + " sent " + to_string(amount) + " to " + toUser;
            pendingTransactions.push_back(txLog);
            cout << "Transaction added to pending pool: [" << txLog << "]\n";
        }

        else if (command == "mine") {
            cout << "Mining a new block... Solving mathematical puzzle...\n";

            string blockData = "";
            for (string tx : pendingTransactions) {
                blockData += tx + " | ";
            }
            if (blockData.empty()) blockData = "No transactions - Empty Block";

            int targetDifficulty = 7; 
            int guessNonce = 0;
            int attempts = 0;

            while (true) {
                guessNonce = rand() % 5000;
                attempts++;
                if (guessNonce % 100 == targetDifficulty) { // Simple math condition met
                    break;
                }
            }

            Block newBlock;
            newBlock.blockIndex = blockchain.size();
            newBlock.data = blockData;
            newBlock.nonce = guessNonce;
            // Link to the index of the last block as a simulated hash pointer
            newBlock.previousHash = blockchain.back().nonce + 12345; 

            blockchain.push_back(newBlock);
            pendingTransactions.clear(); // Flush the pending transaction buffer

            // Reward the Miner (Satoshi) with block reward coins
            balances["System"] -= 50;
            balances["Satoshi"] += 50;

            cout << "🎉 Block #" << newBlock.blockIndex << " successfully MINED after " << attempts << " attempts!\n";
            cout << "Winning Nonce Solution: " << newBlock.nonce << "\n";
            cout << "Mining Reward: +50 coins transferred to [Satoshi].\n";
        }

        else if (command == "chain") {
            cout << "\n=== BLOCKCHAIN LEDGER=== \n";
            for (const Block &b : blockchain) {
                cout << "Block #" << b.blockIndex << "\n";
                cout << "  Data: [" << b.data << "]\n";
                cout << "  Nonce: " << b.nonce << "\n";
                cout << "  Prev Hash Pointer: " << b.previousHash << "\n";
                cout << "-------------------------\n";
            }
            cout << "=========================\n\n";
        }

        else {
            cout << "Unknown command. Available: balance, send, mine, chain, exit\n";
        }
    }

    return 0;
}