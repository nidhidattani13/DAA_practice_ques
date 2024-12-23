#include <bits/stdc++.h>
using namespace std;

int maxZeroSumSubMatrix(vector<vector<int>>& mat, int n, int m) {
    int maxArea = 0;
    
    for (int top = 0; top < n; ++top) {
        vector<int> temp(m, 0);  
        
        for (int bottom = top; bottom < n; ++bottom) {
            for (int col = 0; col < m; ++col) {
                temp[col] += mat[bottom][col];
            }
            
            unordered_map<int, int> sumIndexMap; 
            int currSum = 0;
            
            for (int i = 0; i < m; ++i) {
                currSum += temp[i];
                
                if (currSum == 0) {
                    maxArea = max(maxArea, (bottom - top + 1) * (i + 1));
                }
                
                if (sumIndexMap.find(currSum) != sumIndexMap.end()) {
                    int width = i - sumIndexMap[currSum];
                    maxArea = max(maxArea, (bottom - top + 1) * width);
                } else {
                    sumIndexMap[currSum] = i;
                }
            }
        }
    }
    
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    
    int n = mat.size();
    int m = mat[0].size();
    
    cout << "Largest rectangular sub-matrix with sum 0: " << maxZeroSumSubMatrix(mat, n, m) << endl;
    
    return 0;
}
