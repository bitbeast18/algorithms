// Author : bitbeast18
// Fenwick Tree (BIT).
// Complexity : Build Tree O(N), Query/Update Tree O(log N), Space O(N).

int query(int tree[], int N, int pos) {
    int res = 0;
    for (; pos > 1; pos -= (pos & -pos)) res += tree[pos];
    return res;
}

void update(int tree[], int N, int pos, int val) {
    for (; pos <= N; pos += (pos & -pos)) tree[pos] += val;
}

void build(int tree[], int arr[], int N) {
    for (int id = 1; id <= N; id++) {
        int par = id + (id & -id); // id + LSB(id);
        if (par <= N) tree[par] += arr[id];
    }
}

int main() {

    // Usage
    // build(tree, arr, N);
    // query(tree, N, pos);
    // update(tree, N, pos, update);

    int N;
    int arr[N + 1], tree[N + 1];

    for (int i = 1; i <= N; i++) tree[i] = arr[i];
    return 0;
}
