// Author : bitbeast18
// Kahn's algorithm for topological sorting.
// Complexity : O(V + E).

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> indegree, order;
vector<vector<int>> edges;

void kahn(int n) {

    queue<int> pending;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) pending.push(i);
    }

    while (!pending.empty()) {
        int node = pending.front();
        pending.pop();

        order.push_back(node);

        for (auto adj: edges[node]) {
            if (--indegree[adj] == 0) pending.push(adj);
        }
    }

    if (order.size() != n) cout << "There exists a cycle.";
}

int main() {

    // Usage
    // kahn(int n); Fills the topological ordering in the order vector.
}