#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    int V; 
    unordered_map<int, vector<int>> adj; 

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<double> betweennessCentrality() {
        vector<double> centrality(V, 0.0); 
        vector<int> sigma(V, 0);
        vector<double> delta(V, 0.0); 
        vector<int> dist(V, -1); 
        stack<int> S;
        queue<int> Q;

        for (int s = 0; s < V; ++s) {
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
                        Q.push(w);
                        dist[w] = dist[v] + 1;
                    }
                    if (dist[w] == dist[v] + 1) {
                        sigma[w] += sigma[v];
                    }
                }
            }

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
    int V = 5;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    vector<double> centrality = g.betweennessCentrality();

    cout << "Betweenness Centrality Scores:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": " << centrality[i] << endl;
    }

    return 0;
}
