#include <bits/stdc++.h>
using namespace std;

int maxGoldRecur(int i, int j, vector<vector<int>> &mat) {
    if (i == mat.size() || i < 0 || j == mat[0].size()) return 0;

    int ans = 0;
    ans = max(ans, maxGoldRecur(i - 1, j + 1, mat));
    ans = max(ans, maxGoldRecur(i, j + 1, mat));
    ans = max(ans, maxGoldRecur(i + 1, j + 1, mat));

    return mat[i][j] + ans;
}

int maxGold(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, maxGoldRecur(i, 0, mat));
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {{1, 3, 3}, {2, 1, 4}, {0, 6, 4}};
    cout << maxGold(mat);
    return 0;
}
