#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm> 

using namespace std;

double cosine_similarity(const vector<double>& item1, const vector<double>& item2) {
    double dotProduct = 0, normA = 0, normB = 0;
    for (size_t i = 0; i < item1.size(); ++i) {
        dotProduct += item1[i] * item2[i];
        normA += pow(item1[i], 2);
        normB += pow(item2[i], 2);
    }
    return dotProduct / (sqrt(normA) * sqrt(normB));
}
vector<int> recommend_items(const vector<vector<double>>& itemFeatures, const vector<int>& likedItems, int numRecommendations) {
    unordered_map<int, double> itemScores;
    for (const int& likedItem : likedItems) {
        for (size_t i = 0; i < itemFeatures.size(); ++i) {
            if (itemScores.find(i) == itemScores.end()) {
                itemScores[i] = 0;
            }
            if (likedItem != i) {
                itemScores[i] += cosine_similarity(itemFeatures[likedItem], itemFeatures[i]);
            }
        }
    }
    vector<pair<int, double>> sortedItems(itemScores.begin(), itemScores.end());

    sort(sortedItems.begin(), sortedItems.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
        return b.second < a.second;
    });

    vector<int> recommendations;
    for (int i = 0; i < numRecommendations && i < sortedItems.size(); ++i) {
        recommendations.push_back(sortedItems[i].first);
    }

    return recommendations;
}

int main() {
    vector<vector<double>> itemFeatures = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 0, 1, 0}
    };

    vector<int> likedItems = {0, 2}; 
    int numRecommendations = 3; 

    vector<int> recommendations = recommend_items(itemFeatures, likedItems, numRecommendations);

    cout << "Recommended items for the user are: ";
    for (const int& item : recommendations) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
