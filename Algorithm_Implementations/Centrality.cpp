#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    int V; // Number of vertices
    unordered_map<int, vector<int>> adj; // Adjacency list representation of the graph

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    vector<double> betweennessCentrality() {
        vector<double> centrality(V, 0.0); // Initialize centrality scores
        vector<int> sigma(V, 0); // Number of shortest paths from source
        vector<double> delta(V, 0.0); // Dependency of shortest paths on node
        vector<int> dist(V, -1); // Distance from source node
        stack<int> S;
        queue<int> Q;

        for (int s = 0; s < V; ++s) {
            // Initialization
            fill(sigma.begin(), sigma.end(), 0);
            fill(dist.begin(), dist.end(), -1);
            dist[s] = 0;
            sigma[s] = 1;
            Q.push(s);

            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                S.push(v);

                for (int w : adj[v]) {
                    if (dist[w] < 0) {
                        // w is found for the first time
                        Q.push(w);
                        dist[w] = dist[v] + 1;
                    }
                    if (dist[w] == dist[v] + 1) {
                        // Path to w via v
                        sigma[w] += sigma[v];
                    }
                }
            }

            // Accumulate dependencies
            while (!S.empty()) {
                int w = S.top();
                S.pop();
                for (int v : adj[w]) {
                    if (dist[v] == dist[w] + 1) {
                        delta[v] += (sigma[v] / static_cast<double>(sigma[w])) * (1 + delta[w]);
                    }
                }
                if (w != s) {
                    centrality[w] += delta[w];
                }
            }
        }

        return centrality;
    }
};

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Compute Betweenness Centrality
    vector<double> centrality = g.betweennessCentrality();

    // Print centrality scores
    cout << "Betweenness Centrality Scores:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << centrality[i] << endl;
    }

    return 0;
}
