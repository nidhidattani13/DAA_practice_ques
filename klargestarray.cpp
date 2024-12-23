#include <bits/stdc++.h>
using namespace std;

vector<int> kLargestElements(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < arr.size(); i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {12, 5, 787, 1, 23, 45, 4, 56, 89};
    int k = 3;
    vector<int> result = kLargestElements(arr, k);
    
    cout << "The " << k << " largest elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
