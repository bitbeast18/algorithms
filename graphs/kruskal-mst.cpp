// Author : bitbeast18
// Kruskal's minimum spanning tree algorithm.
// Complexity : O(M*log(N))

#include <vector>
#include <algorithm>

struct Edge {
    int u, v, w;

    friend bool operator<(Edge a, Edge b) {
        return a.w < b.w;
    }
};

const int maxn = 1e5;
int par[maxn];

int root(int x) {
    return (par[x] < 0) ? x : par[x] = root(par[x]);
}

void merge(int u, int v) {
    if ((u = root(u)) == (v = root(v))) return;

    if (par[u] > par[v]) std::swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

std::vector<Edge> edges, ans;

void kruskal(int n) {

    for (int i = 0; i < n; i++) par[i] = -1;

    std::sort(edges.begin(), edges.end());

    int cnt = 0;
    for (auto edge: edges) {
        if (root(edge.u) != root(edge.v)) {
            merge(edge.u, edge.v);
            ans.push_back(edge);
            cnt++;
        }
        if (cnt == n - 1) return;
    }
}

int main() {

    // Usage
    // Initialise edge list.
    // kruskal(n); The list is in ans.

}
