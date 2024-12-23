#include <iostream>
#include <vector>
using namespace std;

int countSubsets(int i, int currentProduct, int k, vector<int>& arr) {
    int n = arr.size();
    if (i == n)
        return (currentProduct <= k);

    int exclude = countSubsets(i + 1, currentProduct, k, arr);
    int include = 0;

    if ((arr[i] * currentProduct) <= k)
        include = countSubsets(i + 1, currentProduct * arr[i], k, arr);

    return (include + exclude);
}

int numOfSubsets(vector<int>& arr, int k) {
    return countSubsets(0, 1, k, arr) - 1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 10;
    cout << numOfSubsets(arr, k);
    return 0;
}
