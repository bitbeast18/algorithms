// Author : bitbeast18

// Lowest Common Ancestor (Brute Force)
// Complexity : < Preprocess : Query > :: < O(N) : O(N) >

const int N = 10; // max_size.
int par[N], h[N]; // helper arrays.
vector<int> tree[N]; // Adjacency List.

void dfs(int v, int p = -1) {
    if (p + 1) h[v] = h[p] + 1;

    par[v] = p;

    for (auto u: tree[v])
        if (p - u) dfs(u, v);

}

int lca(int u, int v) {

    if (u == v) return v;

    if (h[u] < h[v]) swap(u, v);
    return lca(par[u], v);
}

int main() {

    // Usage
    // Initialize h array with 0.
    // int lca = lca(node_a, node_b);

    // Preprocess
    dfs(0);

    // Query
    int ans = lca(0, 1);

    return 0;
}