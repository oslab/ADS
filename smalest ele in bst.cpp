#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the BST
struct node {
    int data;
    struct node *left, *right;
};

// Function to insert a node into the BST
struct node* insert(struct node *r, int key) {
    if (r == NULL) {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = key;
        n->left = n->right = NULL;
        r = n;
    } else if (key > r->data) {
        r->right = insert(r->right, key);
    } else if (key < r->data) {
        r->left = insert(r->left, key);
    }
    return r;
}

// Helper function for in-order traversal to find the k-th smallest element
void inorder(struct node *root, int k, int *count, int *result) {
    if (root != NULL) {
        inorder(root->left, k, count, result);
        (*count)++;
        if (*count == k) {
            *result = root->data;
            return;
        }
        inorder(root->right, k, count, result);
    }
}

int main() {
    struct node* root = NULL;
    int n, val, i, k;
    
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    printf("Enter k to find k-th smallest element: ");
    scanf("%d", &k);
    
    int count = 0;
    int result = -1;
    inorder(root, k, &count, &result);
    
    if (result != -1) {
        printf("The %d-th smallest element is: %d\n", k, result);
    } else {
        printf("There are less than %d elements in the tree.\n", k);
    }
    
    return 0;
}

