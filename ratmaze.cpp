#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findPaths(int i, int j, vector<vector<int>>& mat, vector<string>& res, string path, vector<vector<bool>>& visited) {
        int n = mat.size();
        if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0 || visited[i][j])
            return;
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }
        visited[i][j] = true;
        findPaths(i + 1, j, mat, res, path + "D", visited);
        findPaths(i, j - 1, mat, res, path + "L", visited);
        findPaths(i - 1, j, mat, res, path + "U", visited);
        findPaths(i, j + 1, mat, res, path + "R", visited);
        visited[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> res;
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return res;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        findPaths(0, 0, mat, res, "", visited);
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = sol.findPath(mat);
    for (const string& path : result) {
        cout << path << " ";
    }
    cout << endl;
    return 0;
}
