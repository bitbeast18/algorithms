// Author : bitbeast18

// Segment Tree.
// Complexity : Build Tree : O(N * log N), Query/Update Tree : O(log N).

struct Node {
    // Data Members.
    int x;

    // Member functions.
    void assign(int val) {
        // Some Operations.
    }
};

Node combine(Node a, Node b) {
    Node temp = Node();
    // Some operations.
    return temp;
}

void build(Node *tree, int *arr, int tl, int tr, int node) {
    if (tl == tr) {
        tree[node].assign(arr[tl]);
        return;
    }

    int mid = tl + (tr - tl) / 2;
    build(tree, arr, tl, mid, 2 * node);
    build(tree, arr, mid + 1, tr, 2 * node + 1);
    tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

Node query(Node *tree, int l, int r, int tl, int tr, int node) {

    // Out of Range of current Node.
    if (l > tr || tl > r) {
        Node temp = Node();
        temp.assign(-1); // Garbage Node.
        return temp;
    }

    // Exactly in the Range of current Node.
    if (l <= tl && tr <= r) {
        return tree[node];
    }

    // Partially in left and right.
    int mid = tl + (tr - tl) / 2;
    Node left = query(tree, l, r, tl, mid, 2 * node);
    Node right = query(tree, l, r, mid + 1, tr, 2 * node + 1);
    Node ans = combine(left, right);

    return ans;
}

void update(Node *tree, int *arr, int tl, int tr, int node, int pos, int val) {
    if (tl == tr) {
        arr[pos] = val;
        tree[node].assign(val);
        return;
    }

    int mid = tl + (tr - tl) / 2;
    if (pos > mid) {
        update(tree, arr, mid + 1, tr, 2 * node + 1, pos, val);
    } else {
        update(tree, arr, tl, mid, 2 * node, pos, val);
    }

    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

int main() {

    // Usage
    // Build Tree : build(tree, arr, 0, n-1, 1);
    // Query Tree : query(tree, 0, n-1, ql, qr, 1);
    // Update Tree : update(tree, 0, n-1, 1, pos,val);

    return 0;
}
