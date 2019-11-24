// Author : bitbeast18

// Lowest Common Ancestor in binary trees.
// Complexity : O(N)

struct Node {
    int id;
    Node *left, *right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

int lca(Node *root, int node1, int node2) {
    if (root == nullptr) return -1;
    if (root->id == node1 || root->id == node2) return root->id;

    int left = lca(root->left, node1, node2);
    int right = lca(root->right, node1, node2);

    if (left == -1 && right == -1) return -1;
    if (left != -1 && right != -1) return root->id;

    return left != -1 ? left : right;
}

int main() {

    // Usage
    // int ans = lca(root, node1, node2);

    return 0;
}
