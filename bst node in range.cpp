#include <stdio.h>
#include <stdlib.h>

// Definition of a BST node
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new BST node
struct node* newNode(int key) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

// Function to insert a new node into the BST
struct node* insert(struct node *root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key > root->data) {
        root->right = insert(root->right, key);
    } else if (key < root->data) {
        root->left = insert(root->left, key);
    }
    return root;
}

// Function to count nodes in the given range [key1, key2]
int countNodesInRange(struct node *root, int key1, int key2) {
    // Base case
    if (root == NULL) {
        return 0;
    }

    // Node is in range, count it and check both subtrees
    if (root->data >= key1 && root->data <= key2) {
        return 1 + countNodesInRange(root->left, key1, key2) + countNodesInRange(root->right, key1, key2);
    }
    // If root's data is smaller than key1, then only right subtree can have nodes in range
    else if (root->data < key1) {
        return countNodesInRange(root->right, key1, key2);
    }
    // If root's data is greater than key2, then only left subtree can have nodes in range
    else {
        return countNodesInRange(root->left, key1, key2);
    }
}

int main() {
    struct node* root = NULL;
    int n, val, key1, key2;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter starting and ending range: ");
    scanf("%d%d", &key1, &key2);
    printf("Count: %d\n", countNodesInRange(root, key1, key2));
    return 0;
}

