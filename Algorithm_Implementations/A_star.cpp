#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int x, y;
    int g, h;
    Node* parent;

    Node(int _x, int _y, int _g, int _h, Node* _parent = nullptr)
        : x(_x), y(_y), g(_g), h(_h), parent(_parent) {}

    int f() const { return g + h; }
};

struct CompareNodes {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->f() > rhs->f();
    }
};

bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
}

int calculateH(int x, int y, const pair<int, int>& goal) {
    return abs(x - goal.first) + abs(y - goal.second);
}

vector<pair<int, int>> astar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    if (rows == 0) return {};
    int cols = grid[0].size();

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;

    vector<vector<bool>> closedSet(rows, vector<bool>(cols, false));

    Node* startNode = new Node(start.first, start.second, 0, calculateH(start.first, start.second, goal));
    openSet.push(startNode);

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        closedSet[current->x][current->y] = true;
        
        if (current->x == goal.first && current->y == goal.second) {
            vector<pair<int, int>> path;
            while (current != nullptr) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& dir : directions) {
            int nextX = current->x + dir.first;
            int nextY = current->y + dir.second;

            if (isValid(nextX, nextY, rows, cols, grid)) {
                int newG = current->g + 1;

                Node* neighborNode = new Node(nextX, nextY, newG, calculateH(nextX, nextY, goal), current);

                if (!closedSet[nextX][nextY]) {
                    openSet.push(neighborNode);
                    closedSet[nextX][nextY] = true;
                }
            }
        }
    }

    return {};
}

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
