#include <bits/stdc++.h>
using namespace std;

bool isCompleteGraph(const vector<int>& set, vector<vector<int>>& graph) {
    int size = set.size();
    int edgeCount = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (graph[set[i]][set[j]] == 1) {
                edgeCount++;
            }
        }
    }

    return edgeCount == (size * (size - 1)) / 2;
}

bool checkTwoClique(vector<vector<int>>& graph, int n) {
    vector<int> color(n, -1);

    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    if (graph[node][i] == 1) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[node];
                            q.push(i);
                        } else if (color[i] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    vector<int> set0, set1;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) set0.push_back(i);
        else set1.push_back(i);
    }

    return isCompleteGraph(set0, graph) && isCompleteGraph(set1, graph);
}

int main() {
    int n = 5;
    vector<vector<int>> graph = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    if (checkTwoClique(graph, n)) {
        cout << "The graph can be divided into two cliques." << endl;
    } else {
        cout << "The graph cannot be divided into two cliques." << endl;
    }

    return 0;
}
