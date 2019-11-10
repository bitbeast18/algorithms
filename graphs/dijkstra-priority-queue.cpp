// Author : bitbeast18
// Dijkstra's shortest path algorithm (priority queue).
// Complexity : O(V*log(V))

#include <vector>
#include <queue>

using namespace std;

const int inf = 1e8;
const int maxn = 1e4;

vector<pair<int, int>> edges[maxn];
int dist[maxn], vis[maxn];

void dijkstra(int n) {
    fill(vis, vis + n, false);
    fill(dist, dist + n, inf);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {

        int cur = pq.top().second;
        pq.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (auto adj: edges[cur]) {
            int new_dist = dist[cur] + adj.first;
            if (new_dist < dist[adj.second]) {
                dist[adj.second] = new_dist;
                pq.push({new_dist, adj.second});
            }
        }
    }
}

int main() {

    // Usage
    // dijkstra(edges, dist, n);

    return 0;
}