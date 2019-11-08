// Author : bitbeast18

// Level Order Traversal (Binary Tree)
// Complexity : O(N).

#include <vector>
#include <queue>

std::vector<int> treeOrder;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){
        left = nullptr;
        right = nullptr;
    }
};

void traverse(Node* root){
    if(root == nullptr) return;

    std::queue<Node*> pending;
    pending.push(root);

    while(!pending.empty()){
        Node* currentNode = pending.front();
        pending.pop();

        treeOrder.push_back(currentNode->data);

        if(currentNode->left != nullptr) pending.push(currentNode->left);
        if(currentNode->right != nullptr) pending.push(currentNode->right);
    }
}

int main(){
    // Usage : construct tree --> build();
    // traverse(root);

    Node* root = new Node();
    traverse(root);

    return 0;
}