#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // --- 1. Social Graph Database ---
    // User Name -> Vector of Friends' Names
    map<string, vector<string>> socialGraph;

    // Seeding initial social network profiles
    socialGraph["Alice"] = {"Bob", "Charlie"};
    socialGraph["Bob"] = {"Alice", "David"};
    socialGraph["Charlie"] = {"Alice", "David"};
    socialGraph["David"] = {"Bob", "Charlie"};

    cout << "--- Welcome to the Mini-Social Network Console! ---\n";
    cout << "Commands: 'profile <user>', 'add <user>', 'friend <user1> <user2>', 'suggest <user>', 'exit'\n\n";

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "exit") {
            cout << "Shutting down the social network node. Goodbye!\n";
            break;
        }

        // --- 2. PROFILE Command (View friends list) ---
        else if (command == "profile") {
            string user;
            ss >> user;

            if (!socialGraph.count(user)) {
                cout << "Error: User '" << user << "' does not exist.\n";
                continue;
            }

            cout << "\n=== Profile: " << user << " ===\n";
            cout << "Friends count: " << socialGraph[user].size() << "\n";
            cout << "Friends list: ";
            for (const string &friendName : socialGraph[user]) {
                cout << "[" << friendName << "] ";
            }
            cout << "\n======================\n\n";
        }

        // --- 3. ADD Command (Create a new user node) ---
        else if (command == "add") {
            string user;
            ss >> user;

            if (user.empty()) {
                cout << "Error: Specify a username to add.\n";
                continue;
            }

            if (socialGraph.count(user)) {
                cout << "Error: User '" << user << "' already exists.\n";
            } else {
                socialGraph[user] = vector<string>(); // Initialize empty friends vector
                cout << "Successfully created new profile for [" << user << "].\n";
            }
        }

        // --- 4. FRIEND Command (Connect two users mutually) ---
        else if (command == "friend") {
            string u1, u2;
            ss >> u1 >> u2;

            if (u1.empty() || u2.empty() || u1 == u2) {
                cout << "Error: Invalid users for establishing friendship.\n";
                continue;
            }

            if (!socialGraph.count(u1) || !socialGraph.count(u2)) {
                cout << "Error: One or both profiles do not exist. Create them first using 'add'.\n";
                continue;
            }

            // Check if they are already friends
            auto &f1 = socialGraph[u1];
            if (find(f1.begin(), f1.end(), u2) != f1.end()) {
                cout << "Notice: [" << u1 << "] and [" << u2 << "] are already friends.\n";
                continue;
            }

            // Mutual connection mapping
            socialGraph[u1].push_back(u2);
            socialGraph[u2].push_back(u1);
            cout << "Success: [" << u1 << "] and [" << u2 << "] are now connected friends!\n";
        }

        // --- 5. SUGGEST Command (Friend recommendations based on mutual connections) ---
        else if (command == "suggest") {
            string targetUser;
            ss >> targetUser;

            if (!socialGraph.count(targetUser)) {
                cout << "Error: Profile not found.\n";
                continue;
            }

            cout << "\n=== Friend Suggestions for " << targetUser << " ===\n";
            map<string, int> mutualCount; // Non-friend profile -> mutual friends counter

            // Loop through target user's friends
            for (const string &myFriend : socialGraph[targetUser]) {
                // Loop through friends of my friend (friends-of-friends)
                for (const string &fof : socialGraph[myFriend]) {
                    if (fof == targetUser) continue; // Skip myself
                    
                    // Check if this person is already my friend
                    auto &myFriendsList = socialGraph[targetUser];
                    if (find(myFriendsList.begin(), myFriendsList.end(), fof) != myFriendsList.end()) continue;

                    mutualCount[fof]++; // Found a mutual friend connection
                }
            }

            bool suggestionsFound = false;
            for (auto const& [name, count] : mutualCount) {
                cout << "👤 [" << name << "] — " << count << " mutual friend(s) in common.\n";
                suggestionsFound = true;
            }

            if (!suggestionsFound) {
                cout << "(No suggestions available right now. Connect to more people!)\n";
            }
            cout << "====================================\n\n";
        }

        else {
            cout << "Unknown command. Available: profile, add, friend, suggest, exit\n";
        }
    }

    return 0;
}