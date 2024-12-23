#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

int main() {
    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << longestCommonSubstring(s1, s2);
    return 0;
}
