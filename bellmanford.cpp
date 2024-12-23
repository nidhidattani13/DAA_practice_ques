#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V, E;
    vector<tuple<int, int, int>> edges;
    
    Graph(int V, int E);
    void addEdge(int u, int v, int weight);
    void bellmanFord(int src);
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int weight) {
    edges.push_back(make_tuple(u, v, weight));
}

void Graph::bellmanFord(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Relax edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto& edge : edges) {
            int u, v, weight;
            tie(u, v, weight) = edge;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    // Check for negative weight cycle
    for (auto& edge : edges) {
        int u, v, weight;
        tie(u, v, weight) = edge;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print the distance array
    cout << "Vertex Distance from Source: " << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << ": INF" << endl;
        } else {
            cout << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    Graph g(5, 8);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.bellmanFord(0);

    return 0;
}
