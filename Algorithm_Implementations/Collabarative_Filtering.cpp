#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;
double pearson_correlation(const vector<double>& user1, const vector<double>& user2) {
    double sum1 = 0, sum2 = 0, sum1Sq = 0, sum2Sq = 0, pSum = 0;
    int n = 0;

    for (size_t i = 0; i < user1.size(); ++i) {
        if (user1[i] != 0 && user2[i] != 0) {
            sum1 += user1[i];
            sum2 += user2[i];
            sum1Sq += pow(user1[i], 2);
            sum2Sq += pow(user2[i], 2);
            pSum += user1[i] * user2[i];
            ++n;
        }
    }

    if (n == 0) return 0;

    double num = pSum - (sum1 * sum2 / n);
    double den = sqrt((sum1Sq - pow(sum1, 2) / n) * (sum2Sq - pow(sum2, 2) / n));

    return (den == 0) ? 0 : num / den;
}

double predict_rating(const vector<vector<double>>& ratings, int user, int item) {
    double totalSim = 0;
    double weightedSum = 0;

    for (size_t otherUser = 0; otherUser < ratings.size(); ++otherUser) {
        if (otherUser != user && ratings[otherUser][item] != 0) {
            double sim = pearson_correlation(ratings[user], ratings[otherUser]);
            if (sim > 0) {
                weightedSum += sim * ratings[otherUser][item];
                totalSim += sim;
            }
        }
    }

    return (totalSim == 0) ? 0 : weightedSum / totalSim;
}

int main() {
    vector<vector<double>> ratings = {
        {4, 0, 0, 5, 1, 0, 0},
        {5, 5, 4, 0, 0, 0, 0},
        {0, 0, 0, 2, 4, 5, 0},
        {0, 3, 0, 0, 0, 0, 3}
    };

    int user = 0; 
    int item = 1; 

    double predictedRating = predict_rating(ratings, user, item);

    cout << "Predicted rating for user " << user << " for item " << item << " is " << predictedRating << endl;

    return 0;
}
