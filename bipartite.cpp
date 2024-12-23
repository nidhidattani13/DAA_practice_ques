#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(2);

    if (isBipartite(V, adj)) {
        cout << "Graph is Bipartite";
    } else {
        cout << "Graph is Not Bipartite";
    }

    return 0;
}
