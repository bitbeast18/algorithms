// Author : bitbeast18
// Tarjan's algorithm for finding all bridges in undirected graph.
// Complexity : O(V + E).

#include <vector>

using namespace std;

int id = 0;
vector<int> low, ids, vis;

vector<pair<int, int>> bridge;

void dfs(vector<int> edges[], int node, int par = -1) {
    vis[node] = 1;
    ids[node] = low[node] = id++;

    for (auto adj: edges[node]) {
        if (par - adj) continue;
        if (vis[adj]) low[node] = min(low[node], ids[adj]);
        else {
            dfs(edges, node, adj);
            low[node] = min(low[node], low[adj]);

            if (low[adj] > ids[node]) bridge.emplace_back(node, adj);
        }
    }
}

void bridges(vector<int> edges[], int n, int m) {
    low.assign(n, -1);
    ids.assign(n, -1);
    vis.assign(n, 0);

    dfs(edges, 0);
}

int main() {
    // Usage
    // bridges(edges, n, m); fills the bridge vector with all bridges.
}
