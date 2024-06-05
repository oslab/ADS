#include <stdio.h>
#include <stdlib.h>

// Definition of an AVL Tree node
struct AVL {
    int data;
    struct AVL *left, *right;
    int height;
} *root = NULL;

// Function to get the height of the tree
int height(struct AVL *r) {
    if (r == NULL) return -1;
    else return r->height;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b ? a : b);
}

// Right rotation function
struct AVL *rightrotation(struct AVL *k1) {
    struct AVL *k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), k1->height) + 1;
    return k2;
}

// Left rotation function
struct AVL *leftrotation(struct AVL *k1) {
    struct AVL *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    return k2;
}

// Left-Right rotation function
struct AVL *leftrightrotation(struct AVL *k1) {
    k1->left = leftrotation(k1->left);
    return rightrotation(k1);
}

// Right-Left rotation function
struct AVL *rightleftrotation(struct AVL *k1) {
    k1->right = rightrotation(k1->right);
    return leftrotation(k1);
}

// Function to insert a node in the AVL tree
struct AVL *insert(struct AVL *root, int key) {
    if (root == NULL) {
        root = (struct AVL *)malloc(sizeof(struct AVL));
        root->data = key;
        root->height = 0;
        root->left = root->right = NULL;
    } else if (key < root->data) {
        root->left = insert(root->left, key);
        if (height(root->left) - height(root->right) == 2) {
            if (key < root->left->data) root = rightrotation(root);
            else root = leftrightrotation(root);
        }
    } else if (key > root->data) {
        root->right = insert(root->right, key);
        if (height(root->left) - height(root->right) == -2) {
            if (key > root->right->data) root = leftrotation(root);
            else root = rightleftrotation(root);
        }
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

// Function to display the AVL tree
void display(struct AVL *r, int level) {
    int i;
    if (r != NULL) {
        display(r->right, level + 1);
        printf("\n");
        if (r == root) printf("root-> ");
        for (i = 0; i < level && r != root; i++) printf("       ");
        printf("%d", r->data);
        display(r->left, level + 1);
    }
}

int main() {
    int ch, key;
    printf("1.INSERTION 2.DISPLAY\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the node to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                if (root == NULL) {
                    printf("The tree is empty");
                    continue;
                }
                printf("\nAVL tree is: ");
                display(root, 1);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}

