// Author : bitbeast18
// Tarjan's algorithm for finding all articulation points in undirected graph.
// Complexity : O(V + E).

#include <vector>

using namespace std;

int id = 0;
vector<int> low, ids, vis;

vector<int> articulation;

void dfs(vector<int> edges[], int node, int par = -1) {
    vis[node] = 1;
    ids[node] = low[node] = id++;

    int child = 0;
    for (auto adj: edges[node]) {
        if (par - adj) continue;
        if (vis[adj]) low[node] = min(low[node], ids[adj]);
        else {
            dfs(edges, node, adj);
            low[node] = min(low[node], low[adj]);
            child++;
            if (low[adj] >= ids[node] && par != -1) articulation.push_back(node);
        }
    }

    if (par == -1 && child > 1) articulation.push_back(node);
}

void articulations(vector<int> edges[], int n, int m) {
    low.assign(n, -1);
    ids.assign(n, -1);
    vis.assign(n, 0);

    dfs(edges, 0);
}

int main() {
    // Usage
    // articulations(edges, n, m); fills the articulation vector with all articulation points.
}
