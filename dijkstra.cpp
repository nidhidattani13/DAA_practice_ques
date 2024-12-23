#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<pair<int, int>>* adj;

    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

void Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    set<pair<int, int>> s;
    s.insert({0, src});
    
    while (!s.empty()) {
        int u = s.begin()->second;
        s.erase(s.begin());

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if (dist[u] + weight < dist[v]) {
                if (dist[v] != INT_MAX) {
                    s.erase(s.find({dist[v], v}));
                }
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);
    return 0;
}
