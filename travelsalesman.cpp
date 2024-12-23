#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int tsp(int mask, int pos, vector<vector<int>>& dist, vector<vector<int>>& dp, int n) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];  // Return to the starting point
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {  // If the city is not visited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp, n);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<vector<int>> dp((1 << n), vector<int>(n, -1)); // DP table initialized with -1

    cout << "Minimum cost to visit all cities: " << tsp(1, 0, dist, dp, n) << endl;

    return 0;
}
