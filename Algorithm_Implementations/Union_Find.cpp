#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find operation with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Union operation by rank
    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
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

    // Check if two elements are in the same set
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    int n = 6; // Number of elements
    UnionFind uf(n);

    // Perform union operations
    uf.unionSet(0, 1);
    uf.unionSet(1, 2);
    uf.unionSet(3, 4);
    uf.unionSet(4, 5);

    // Check connectivity
    cout << "Is 0 connected to 2? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl; // Should print Yes
    cout << "Is 1 connected to 5? " << (uf.isConnected(1, 5) ? "Yes" : "No") << endl; // Should print No

    return 0;
}
