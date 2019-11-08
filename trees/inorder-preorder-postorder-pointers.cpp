// Author : bitbeast18

// Inorder/Preorder/Postorder Traversal (Binary Tree).
// Complexity : O(N).

#include <vector>

std::vector<int> treeOrder;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *root) {
    if (root == nullptr) return;

    inorder(root->left);
    treeOrder.push_back(root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == nullptr) return;

    treeOrder.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    treeOrder.push_back(root->data);
}

int main() {
    // Usage : construct tree --> build();
    // inorder(root);
    // preorder(root);
    // postorder(root);

    Node *root = new Node();
    inorder(root);
    preorder(root);
    postorder(root);

    return 0;
}