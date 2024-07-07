#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

vector<int> dijkstra(const vector<vector<pii>>& graph, int start, int n) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    int start = 0; // Starting node

    // Example graph representation: adjacency list with weights
    vector<vector<pii>> graph(n);
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    vector<int> shortest_paths = dijkstra(graph, start, n);

    // Output shortest paths from the start node
    cout << "Shortest paths from node " << start << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << ": ";
        if (shortest_paths[i] == INF)
            cout << "INF" << endl;
        else
            cout << shortest_paths[i] << endl;
    }

    return 0;
}
