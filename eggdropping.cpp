#include <iostream>
#include <vector>
using namespace std;

int eggDrop(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 1)
                dp[i][j] = j;
            else {
                dp[i][j] =INT8_MAX;
                for (int x = 1; x <= j; x++) {
                    int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                    dp[i][j] = min(dp[i][j], res);
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}
