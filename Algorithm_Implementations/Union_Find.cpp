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
            parent[i] = i; 
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

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
    bool isConnected(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    int n = 6;
    UnionFind uf(n);

    uf.unionSet(0, 1);
    uf.unionSet(1, 2);
    uf.unionSet(3, 4);
    uf.unionSet(4, 5);

    cout << "Is 0 connected to 2? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Is 1 connected to 5? " << (uf.isConnected(1, 5) ? "Yes" : "No") << endl; 

    return 0;
}
