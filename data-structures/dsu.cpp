// Author : bitbeast18

// Disjoint Set Union using Rooted Tree.
// Path compression and rank comparison.
// Complexity : O( M * a(M, N) ) where a() is inverse Ackermann's function.
// M is no. of merge operations and N is no. of objects.

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e5;

int par[maxn];

int root(int u){
    return par[u] < 0 ? u : par[u] = root(par[u]);
}

void unite(int u, int v){
    if((u = root(u)) == (v == root(v))) return;
    if(par[v] > par[u]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
}

int main() {

    memset(par, -1, sizeof par);

    //    usage:
    //    unite(u, v);
    //    int parent = root(u);
}