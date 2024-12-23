#include <bits/stdc++.h>
using namespace std;

int findMinDiff(vector<int>& arr, int n, int m) {
    if (m == 0 || n == 0) return 0;

    sort(arr.begin(), arr.end());

    if (n < m) return -1;

    int min_diff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        min_diff = min(min_diff, diff);
    }

    return min_diff;
}

int main() {
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 40, 40, 28, 42, 30, 40, 40};
    int n = arr.size();
    int m = 7;
    
    int result = findMinDiff(arr, n, m);
    cout << "Minimum difference is " << result << endl;
    
    return 0;
}
