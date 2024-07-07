#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
    unordered_map<int, vector<int>> adj_list;

public:
    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // for undirected graph
    }

    void bfs(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj_list[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "BFS starting from node 2:" << endl;
    g.bfs(2);

    return 0;
}
