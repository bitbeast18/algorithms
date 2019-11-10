// Author : bitbeast18
// Euler Tour of Tree (Converts Tree to an Array).
// Complexity : O(N).

#include <vector>

using namespace std;

const int maxn = 10;

vector<int> euler_tour;
vector<int> edges[maxn];

void dfs(int v, int p = 0) {
    euler_tour.push_back(v);

    for (auto u: edges[v])
        if (p - u) dfs(u, v), euler_tour.push_back(v);
}

int main() {
    // Usage : dfs(0); Fills the euler_tour array.
    dfs(0);
}