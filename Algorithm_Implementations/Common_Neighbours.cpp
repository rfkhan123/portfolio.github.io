#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Define a graph class using adjacency list representation
class Graph {
private:
    unordered_map<int, unordered_set<int>> adjList;

public:
    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    // Function to calculate common neighbors between two nodes
    int commonNeighbors(int u, int v) {
        int count = 0;
        for (int neighbor : adjList[u]) {
            if (adjList[v].find(neighbor) != adjList[v].end()) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    // Create a graph instance
    Graph G;

    // Add edges (replace with your own data)
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 4);

    // Example usage: Calculate common neighbors between nodes 1 and 3
    int node1 = 1;
    int node2 = 3;
    int commonNeighborsCount = G.commonNeighbors(node1, node2);

    cout << "Number of common neighbors between nodes " << node1 << " and " << node2 << ": " << commonNeighborsCount << endl;

    return 0;
}
