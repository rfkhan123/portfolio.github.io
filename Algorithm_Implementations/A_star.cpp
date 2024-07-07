#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

// Node structure to represent each cell in the grid
struct Node {
    int x, y;
    int g, h;
    Node* parent;

    Node(int _x, int _y, int _g, int _h, Node* _parent = nullptr)
        : x(_x), y(_y), g(_g), h(_h), parent(_parent) {}

    int f() const { return g + h; }
};

// Custom comparator for priority queue based on f value
struct CompareNodes {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->f() > rhs->f();
    }
};

// Function to check if a cell is within grid bounds and is passable
bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
}

// Function to calculate heuristic (Manhattan distance)
int calculateH(int x, int y, const pair<int, int>& goal) {
    return abs(x - goal.first) + abs(y - goal.second);
}

// A* search algorithm
vector<pair<int, int>> astar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    if (rows == 0) return {}; // Handle empty grid
    int cols = grid[0].size();

    // Directions for moving in 4 possible directions (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Priority queue for open set
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;

    // Closed set to track visited nodes
    vector<vector<bool>> closedSet(rows, vector<bool>(cols, false));

    // Create the start node
    Node* startNode = new Node(start.first, start.second, 0, calculateH(start.first, start.second, goal));
    openSet.push(startNode);

    // A* algorithm loop
    while (!openSet.empty()) {
        // Get the node with the lowest f value
        Node* current = openSet.top();
        openSet.pop();

        // Mark the current node as visited
        closedSet[current->x][current->y] = true;

        // If goal is reached, construct the path and return
        if (current->x == goal.first && current->y == goal.second) {
            vector<pair<int, int>> path;
            while (current != nullptr) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Process each neighbor
        for (const auto& dir : directions) {
            int nextX = current->x + dir.first;
            int nextY = current->y + dir.second;

            // Check if the neighbor is valid
            if (isValid(nextX, nextY, rows, cols, grid)) {
                // Calculate g value for the neighbor
                int newG = current->g + 1;

                // Create the neighbor node
                Node* neighborNode = new Node(nextX, nextY, newG, calculateH(nextX, nextY, goal), current);

                // If neighbor is not in closed set, add to open set
                if (!closedSet[nextX][nextY]) {
                    openSet.push(neighborNode);
                    closedSet[nextX][nextY] = true;
                }
            }
        }
    }

    // No path found
    return {};
}

// Example usage
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    vector<pair<int, int>> path = astar(grid, start, goal);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:" << endl;
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
