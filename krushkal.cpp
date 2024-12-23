#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V, E;
    vector<pair<int, pair<int, int>>> edges;
    
    Graph(int V, int E);
    void addEdge(int u, int v, int weight);
    int findParent(int i, vector<int>& parent);
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank);
    void kruskalMST();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int weight) {
    edges.push_back({weight, {u, v}});
}

int Graph::findParent(int i, vector<int>& parent) {
    if (parent[i] == i) return i;
    return parent[i] = findParent(parent[i], parent);
}

void Graph::unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end());

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;
    for (auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (findParent(u, parent) != findParent(v, parent)) {
            mstWeight += weight;
            unionSets(u, v, parent, rank);
        }
    }

    cout << "Weight of MST: " << mstWeight << endl;
}

int main() {
    Graph g(4, 5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
