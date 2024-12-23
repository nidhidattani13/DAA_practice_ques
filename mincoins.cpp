#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 5, 10, 25};
    int amount = 30;
    int result = minCoins(coins, amount);
    
    if (result != -1)
        cout << "Minimum number of coins: " << result << endl;
    else
        cout << "Not possible to make the amount with given coins." << endl;
    
    return 0;
}
