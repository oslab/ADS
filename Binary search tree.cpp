#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    struct node* right;
    int data;
};

void inorder(struct node* r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node* r) {
    if (r != NULL) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node* r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

int findmin(struct node* r) {
    if (r->left != NULL) {
        return findmin(r->left);
    }
    return r->data;
}

int findmax(struct node* r) {
    if (r->right != NULL) {
        return findmax(r->right);
    }
    return r->data;
}

void search(struct node* r, int key) {
    if (r != NULL) {
        if (key == r->data) {
            printf("Found\n");
            return;
        } else if (key < r->data) {
            search(r->left, key);
        } else {
            search(r->right, key);
        }
    } else {
        printf("Not found\n");
    }
}

struct node* insertion(struct node* r, int val) {
    if (r == NULL) {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->left = NULL;
        n->right = NULL;
        r = n;
    } else if (val < r->data) {
        r->left = insertion(r->left, val);
    } else {
        r->right = insertion(r->right, val);
    }
    return r;
}

int main() {
    struct node* r = NULL;
    int n, val, x;

    printf("Enter size: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        r = insertion(r, val);
    }

    printf("\nInorder:\n");
    inorder(r);
    printf("\nPreorder:\n");
    preorder(r);
    printf("\nPostorder:\n");
    postorder(r);
    printf("\nMin: %d", findmin(r));
    printf("\nMax: %d", findmax(r));
    printf("\nEnter a number to search: ");
    scanf("%d", &x);
    search(r, x);

    return 0;
}

