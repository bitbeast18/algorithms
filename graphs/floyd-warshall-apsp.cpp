// Author  : bitbeast18
// Floyd Warshall :  All pair shortest paths.
// Complexity : O(V^3).

#include <algorithm>

const int maxn = 500;
int d[maxn][maxn];

void floyd_warshall(int n){

    for(int k=0; k<n; k++)
        for(int i=0; i<n;  i++)
            for(int j=0;j<n; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
}

int main(){

    // Initialise graph.
    // d[i][j] = weight or inf.

    return 0;
}