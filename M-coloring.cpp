#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool mColoringUtil(int node, vector<vector<int>>& graph, int m, vector<int>& colors) {
    if (node == graph.size()) {
        return true; // All nodes have been assigned colors
    }
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, colors, c)) {
            colors[node] = c;
            if (mColoringUtil(node + 1, graph, m, colors)) {
                return true;
            }
            colors[node] = 0; // Backtrack
        }
    }
    
    return false;
}

bool mColoring(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> colors(n, 0); // Initialize all colors as 0 (no color)
    
    if (mColoringUtil(0, graph, m, colors)) {
        return true; // It is possible to color the graph
    }
    return false; // It is not possible to color the graph
}

int main() {
    int m = 3; // Number of colors
    vector<vector<int>> graph = {
        {0, 1, 1, 1}, // Adjacency matrix for the graph
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    
    if (mColoring(graph, m)) {
        cout << "Graph can be colored with " << m << " colors\n";
    } else {
        cout << "Graph cannot be colored with " << m << " colors\n";
    }
    
    return 0;
}
