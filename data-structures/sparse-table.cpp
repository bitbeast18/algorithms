// Author : bitbeast18
// Sparse Table for RMQ.
// Complexity : < preprocess : query > :: < O(N*log(N)) : O(1) >

#include <algorithm>

const int maxn = 1e5 + 10;
const int logmax = 20;

int table[logmax][maxn];

int log(int x) {
    return 31 - __builtin_clz(x);
}

void init(const int arr[], int n) {
    for (int i = 0; i < n; i++) table[0][i] = arr[i];

    for (unsigned int i = 1; (1u << i) <= n; i++) {
        for (unsigned int j = 0; j + (1u << i) <= n; j++) {
            table[i][j] = std::min(table[i - 1][j], table[i - 1][j + (1u << (i - 1))]);
        }
    }
}

int query(int l, int r) {
    unsigned int base = log(r - l + 1);
    return std::min(table[base][l], table[base][r - (1u << base) + 1]);
}

int main() {

    // 0-based indexing.

    int arr[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    init(arr, 10);

    // Usage
    // int ans = query(6, 9);
}