// Author : bitbeast18
// Topological sorting using dfs.
// Complexity : O(V + E).

#include <vector>
#include <algorithm>

using namespace std;

vector<int> order, vis;
vector<vector<int>> edges;

void dfs(int node) {
    vis[node] = true;

    for (auto adj: edges[node])
        if (!vis[adj]) dfs(adj);

    order.push_back(node);
}

void toposort(int n) {

    vis.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);

    reverse(order.begin(), order.end());
}

int main() {

    // Usage
    // toposort(n); Fills the topological ordering of graph in order vector.
}