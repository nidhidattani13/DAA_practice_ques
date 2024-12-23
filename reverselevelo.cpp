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

void reverseLevelOrder(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        s.push(temp->data);
        q.pop();
        
        if (temp->right != nullptr) q.push(temp->right);
        if (temp->left != nullptr) q.push(temp->left);
    }
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
    reverseLevelOrder(root);
    
    return 0;
}
