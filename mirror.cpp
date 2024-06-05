#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if two trees are mirror images of each other.
bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    // If both subtrees are empty, they are mirrors.
    if (!left && !right)
        return true;
    
    // If one subtree is empty and the other is not, they are not mirrors.
    if (!left || !right)
        return false;
    
    // Check if current nodes are equal and the subtrees are mirrors of each other.
    return (left->val == right->val) && 
           isMirror(left->left, right->right) && 
           isMirror(left->right, right->left);
}

// Function to check if a tree is symmetric.
bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

// Helper function to create a new tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Test case 1: asymmetric tree
    struct TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->right = newNode(3);
    root1->right->right = newNode(3);
    printf("Tree 1 is symmetric: %s\n", isSymmetric(root1) ? "true" : "false");

    // Test case 2: symmetric tree
    struct TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(3);
    root2->left->right = newNode(4);
    root2->right->left = newNode(4);
    root2->right->right = newNode(3);
    printf("Tree 2 is symmetric: %s\n", isSymmetric(root2) ? "true" : "false");

    return 0;
}

