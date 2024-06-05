#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    struct node* right;
    int data;
};

struct node* findlca(struct node* r, int p, int q) {
    if (r == NULL) {
        return NULL;
    }

    if (r->data > p && r->data > q) {
        return findlca(r->left, p, q);
    }

    if (r->data < p && r->data < q) {
        return findlca(r->right, p, q);
    }

    return r;
}

struct node* insert(struct node* r, int val) {
    if (r == NULL) {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->left = NULL;
        n->right = NULL;
        r = n;
    } else if (val < r->data) {
        r->left = insert(r->left, val);
    } else {
        r->right = insert(r->right, val);
    }
    return r;
}

int main() {
    struct node* r = NULL;
    int n, val, p, q;

    printf("Enter size: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        r = insert(r, val);
    }

    printf("Enter two values of tree:\n");
    scanf("%d%d", &p, &q);

    struct node* lca = findlca(r, p, q);
    if (lca != NULL) {
        printf("\nLCA: %d\n", lca->data);
    } else {
        printf("\nLCA not found\n");
    }

    return 0;
}

