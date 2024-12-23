#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr)
        totalSum += num;

    if (totalSum % 2 != 0)
        return false;

    int target = totalSum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    cout << (canPartition(arr) ? "true" : "false");
    return 0;
}
