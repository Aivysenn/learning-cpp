#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    map<string, map<string, int>> ratings;

    // Seeding sample database profiles
    ratings["Alice"]["Inception"] = 5;
    ratings["Alice"]["The_Matrix"] = 5;
    ratings["Alice"]["Interstellar"] = 4;

    ratings["Bob"]["Inception"] = 5;
    ratings["Bob"]["The_Matrix"] = 4;
    ratings["Bob"]["Titanic"] = 5;

    ratings["Charlie"]["Titanic"] = 5;
    ratings["Charlie"]["The_Notebook"] = 4;
    ratings["Charlie"]["Interstellar"] = 2;

    cout << "--- Welcome to the AI Movie Recommendation Engine! ---\n";
    cout << "Profiles available in database: Alice, Bob, Charlie\n";
    cout << "Enter target user name to generate personalized recommendations:\n";

    string targetUser;
    getline(cin, targetUser);

    if (!ratings.count(targetUser)) {
        cout << "Error: User profile '" << targetUser << "' not found in database.\n";
        return 1;
    }

    string bestMatchUser = "";
    int maxCommonHighRatings = 0;

    for (auto const& [user, movieMap] : ratings) {
        if (user == targetUser) continue; // Skip comparing the user with themselves

        int currentMatchScore = 0;
        
        for (auto const& [movie, rating] : ratings[targetUser]) {
            if (movieMap.count(movie) && rating >= 4 && movieMap.at(movie) >= 4) {
                currentMatchScore++;
            }
        }

        if (currentMatchScore > maxCommonHighRatings) {
            maxCommonHighRatings = currentMatchScore;
            bestMatchUser = user;
        }
    }

    cout << "\n=== AI Recommendation Report ===\n";
    if (bestMatchUser.empty() || maxCommonHighRatings == 0) {
        cout << "Result: No profile matches found with similar tastes.\n";
        cout << "Trending Recommendation: [Inception] (Overall community top pick).\n";
    } else {
        cout << "Taste Match Partner Identified: [" << bestMatchUser << "]\n";
        cout << "Recommended items you haven't watched yet:\n";
        
        bool foundRecommendation = false;
        
        for (auto const& [movie, rating] : ratings[bestMatchUser]) {
            if (!ratings[targetUser].count(movie) && rating >= 4) {
                cout << "⭐ [" << movie << "] (Rated " << rating << "/5 by " << bestMatchUser << ")\n";
                foundRecommendation = true;
            }
        }

        if (!foundRecommendation) {
            cout << "(You have already watched all high-rated movies from your match profile!)\n";
        }
    }
    cout << "================================\n";

    return 0;
}