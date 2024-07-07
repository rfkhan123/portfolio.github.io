#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a struct for tasks with priority
struct Task {
    int priority;
    string name;

    Task(int priority, const string& name) : priority(priority), name(name) {}

    // Overload the '<' operator for min-heap based on priority
    bool operator<(const Task& other) const {
        // Higher priority tasks should come before lower priority tasks
        return priority > other.priority;
    }
};

int main() {
    // Priority queue to store tasks (min-heap based on priority)
    priority_queue<Task> pq;

    // Insert tasks with priorities
    pq.push(Task(2, "Task B"));
    pq.push(Task(1, "Task A"));
    pq.push(Task(3, "Task C"));

    // Process tasks in priority order
    while (!pq.empty()) {
        Task current = pq.top();
        pq.pop();
        cout << "Task Name: " << current.name << ", Priority: " << current.priority << endl;
    }

    return 0;
}
