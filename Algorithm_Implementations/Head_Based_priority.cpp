#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Task {
    int priority;
    string name;

    Task(int priority, const string& name) : priority(priority), name(name) {}

    bool operator<(const Task& other) const {
        return priority > other.priority;
    }
};

int main() {
    priority_queue<Task> pq;
    pq.push(Task(2, "Task B"));
    pq.push(Task(1, "Task A"));
    pq.push(Task(3, "Task C"));

    while (!pq.empty()) {
        Task current = pq.top();
        pq.pop();
        cout << "Task Name: " << current.name << ", Priority: " << current.priority << endl;
    }

    return 0;
}
