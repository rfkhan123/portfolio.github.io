#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class PageRank {
    unordered_map<int, vector<int>> outgoing_links;
    unordered_map<int, vector<int>> incoming_links;
    unordered_map<int, double> rank;

public:
    void add_edge(int from, int to) {
        outgoing_links[from].push_back(to);
        incoming_links[to].push_back(from); 
    }

    void initialize_rank() {
        for (auto& pair : outgoing_links) {
            int node = pair.first;
            rank[node] = 1.0; 
        }
    }

    void compute_pagerank(int iterations, double damping_factor) {
        int num_nodes = rank.size();
        unordered_map<int, double> new_rank;

        for (int iter = 0; iter < iterations; ++iter) {
            for (auto& pair : rank) {
                int node = pair.first;
                double new_pr = (1 - damping_factor); 
                for (int incoming_node : incoming_links[node]) {
                    int num_outgoing_links = outgoing_links[incoming_node].size();
                    new_pr += damping_factor * rank[incoming_node] / num_outgoing_links;
                }
                new_rank[node] = new_pr;
            }
            rank = new_rank;
        }
    }

    void print_pagerank() {
        cout << "PageRank values:" << endl;
        for (auto& pair : rank) {
            cout << "Node " << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
    PageRank pr;

    pr.add_edge(1, 2);
    pr.add_edge(2, 1);
    pr.add_edge(2, 3);
    pr.add_edge(3, 1);
    pr.add_edge(3, 2);

    pr.initialize_rank();
    pr.compute_pagerank(20, 0.85);
    pr.print_pagerank();

    return 0;
}
