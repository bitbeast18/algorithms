// Author : bitbeast18
// Dijkstra's shortest path algorithm (standard)
// Complexity : O(V * V)

#include <vector>

using namespace std;

const int maxn = 1e4;
const int inf = 1e8;

vector<pair<int, int>> edges[maxn];
int dist[maxn], vis[maxn];

void dijkstra(int n, int src) {
    fill(dist, dist + n, inf);
    fill(vis, vis + n, false);

    dist[0] = 0;

    while (true) {
        int v = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (v == -1 || dist[i] < dist[v])) v = i;
        }

        if (v == -1) break;

        for (auto adj: edges[v]) {
            dist[adj.first] = min(dist[adj.first], dist[v] + adj.second);
        }
    }
}

int main() {

    // Usage
    // dijkstra(n, 0);

    return 0;
}