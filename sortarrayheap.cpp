#include <bits/stdc++.h>
using namespace std;

void heapSort(vector<int>& arr) {
    make_heap(arr.begin(), arr.end());
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        pop_heap(arr.begin(), arr.begin() + i + 1);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    heapSort(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
