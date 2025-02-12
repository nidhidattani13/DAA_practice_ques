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

void rightView(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            if (i == n - 1) cout << temp->data << " ";
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    cout << "Right view: ";
    rightView(root);
    cout << endl;
    
    return 0;
}
