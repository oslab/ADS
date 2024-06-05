#include <stdio.h>
#define maxn 10000
#define INF 1000000000

int n, a[maxn], tmp[maxn << 1];

// Function to determine the winner between two positions
int winner(int pos1, int pos2) {
    int u = pos1 >= n ? pos1 : tmp[pos1];
    int v = pos2 >= n ? pos2 : tmp[pos2];
    if (tmp[u] <= tmp[v]) return u;
    return v;
}

// Function to create the initial tournament tree
void create_tree(int *value) {
    for (int i = 0; i < n; i++) tmp[n + i] = i; // Initialize leaves with indices
    for (int i = 2 * n - 1; i > 1; i -= 2) {
        int k = i / 2;
        int j = i - 1;
        tmp[k] = winner(i, j);
    }
    *value = a[tmp[1]]; // Store the smallest element's value
    a[tmp[1]] = INF; // Set the smallest element's position to INF
}

// Function to recreate the tournament tree after extracting the minimum element
void recreate(int *value) {
    int i = tmp[1];
    while (i > 1) {
        int j, k = i / 2;
        if (i % 2 == 0 && i < 2 * n - 1)
            j = i + 1;
        else
            j = i - 1;
        tmp[k] = winner(i, j);
        i = k;
    }
    *value = a[tmp[1]]; // Store the smallest element's value
    a[tmp[1]] = INF; // Set the smallest element's position to INF
}

// Function to perform tournament sort
void tournament_sort() {
    int value;
    create_tree(&value);
    for (int i = 0; i < n; i++) {
        a[i] = value;
        recreate(&value);
    }
}

int main() {
    int testcase;
    printf("Enter the number of test cases: ");
    scanf("%d", &testcase);
    while (testcase--) {
        printf("Enter the size: ");
        scanf("%d", &n);
        printf("Enter the elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        tournament_sort();
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}

