// Author : bitbeast18
// Bellman Ford for single source shortest path with negative weights.
// Complexity : O(V*E)

#include <vector>

const int maxn = 400;
const int inf = 1e8;

struct Edge {
    int u, v, w;
};

std::vector<Edge> edges;
int dist[maxn];

bool bellman_ford(int n) {

    for (int i = 0; i < n; i++) dist[i] = inf;
    dist[0] = 0;

    for (int i = 0; i < n; i++) {
        for (auto edge: edges) {
            if (dist[edge.v] > dist[edge.u] + edge.w) {
                if (i == n - 1) return true;
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    return false;
}

int main() {

    // Usage.
    // Edge list implementation. Returns true if graph has negative cycle.
    // bool hasNegativeCycle = bellman_ford(n);

    return 0;
}