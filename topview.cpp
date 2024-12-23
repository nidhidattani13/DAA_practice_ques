#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void topView(Node* root) {
    if (root == nullptr) return;
    
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    
    while (!q.empty()) {
        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        
        if (mp.find(hd) == mp.end()) {
            mp[hd] = temp->data;
        }
        
        if (temp->left) q.push({temp->left, hd - 1});
        if (temp->right) q.push({temp->right, hd + 1});
    }
    
    for (auto it : mp) {
        cout << it.second << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    cout << "Top view: ";
    topView(root);
    cout << endl;
    
    return 0;
}
