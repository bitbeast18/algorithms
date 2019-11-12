// Author : bitbeast18
// Hierholzer's algorithm for finding eulerian path or cycle.
// Complexity : O(E).

#include <vector>
#include <algorithm>

using namespace std;

vector<int> pos, indeg, path;
vector<vector<int>> edges;

void dfs(int node) {
    while (pos[node] < (int) edges[node].size()) dfs(edges[node][pos[node]++]);
    path.push_back(node);
}

bool eulerianPath(int n, int m) {

    pos.assign(n, 0);
    indeg.assign(n, 0);

    // Existence check;
    int src = -1, tgt = -1;
    for (int i = 0; i < n; i++) {
        if (abs((int) edges[i].size() - indeg[i]) > 1) return false;
        if ((int) edges.size() > indeg[i]) {
            if (src == -1) src = i;
            else return false;
        }
        if ((int) edges[i].size() < indeg[i]) {
            if (tgt == -1) tgt = i;
            else return false;
        }
    }

    if (src != -1 && tgt == -1) return false;
    if (src == -1 && tgt != -1) return false;

    dfs(src);
    reverse(path.begin(), path.end());

    return (int) path.size() == m + 1;
}

int main() {

    // Usage
    // eulerianPath(n, m); returns true if path exists.

}