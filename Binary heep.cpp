#include <stdio.h>

// Function to heapify a subtree rooted with node i which is an index in array a[]. n is the size of the heap
void heapify(int a[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

// Function to build a Max-Heap from the array
void buildHeap(int a[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// Function to perform heap sort
void heapsort(int a[], int n) {
    // Build heap (rearrange array)
    buildHeap(a, n);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    heapsort(a, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

