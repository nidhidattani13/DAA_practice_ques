#include <bits/stdc++.h>
using namespace std;

vector<int> kLargestElements(vector<int>& arr, int k) {
    priority_queue<int> maxHeap;
    
    for (int num : arr) {
        maxHeap.push(num);
    }
    
    vector<int> result;
    for (int i = 0; i < k && !maxHeap.empty(); i++) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }
    
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
