// Author : bitbeast18
// Kosaraju's algorithm to find strongly connected components.
// Complexity : O(V + E).

#include <vector>
#include <stack>

using namespace std;

vector<bool> vis;
vector<vector<int>> g, gr, components;

void dfs1(int node, stack<int> &order) {
    vis[node] = true;
    for (auto adj: g[node]) {
        if (!vis[adj]) dfs1(adj, order);
    }

    order.push(node);
}

void dfs2(int node, vector<int> &component) {
    vis[node] = true;
    component.push_back(node);

    for (auto adj: gr[node]) {
        if (!vis[adj]) dfs2(adj, component);
    }
}

void kosaraju(int n) {

    stack<int> order;

    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i, order);
    }


    vis.assign(n, false);
    while (!order.empty()) {
        int node = order.top();
        order.pop();
        if (!vis[node]) {
            vector<int> component;
            dfs2(node, component);
            components.push_back(component);
        }
    }
}

int main() {

    // Usage

    // g.resize(n);
    // gr.resize(n);

    // kosaraju(n); fills the components vector with all SCCs.

    return 0;
}
