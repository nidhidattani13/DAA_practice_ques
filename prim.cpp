#include <bits/stdc++.h>
using namespace std;

class PrimGraph {
public:
    int V;
    vector<pair<int, int>>* adj;
    
    PrimGraph(int V);
    void addEdge(int u, int v, int weight);
    void primMST();
};

PrimGraph::PrimGraph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void PrimGraph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

void PrimGraph::primMST() {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mstSet(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        mstSet[u] = true;
        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    int mstWeight = 0;
    for (int i = 1; i < V; i++) {
        mstWeight += key[i];
    }

    cout << "Weight of MST: " << mstWeight << endl;
}

int main() {
    PrimGraph p(4);
    p.addEdge(0, 1, 10);
    p.addEdge(0, 2, 6);
    p.addEdge(0, 3, 5);
    p.addEdge(1, 3, 15);
    p.addEdge(2, 3, 4);

    p.primMST();

    return 0;
}
