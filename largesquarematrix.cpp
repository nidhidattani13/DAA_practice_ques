#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxSide = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mat[i - 1][j - 1] == 1) {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide;
}

int main() {
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, 
                               {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0},
                               {1, 1, 1, 1, 0},
                               {1, 1, 1, 1, 1},
                               {0, 0, 0, 0, 0}};
    cout << maximalSquare(mat);
    return 0;
}
