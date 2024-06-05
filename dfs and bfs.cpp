#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function for BFS traversal from a given source vertex
void BFS(struct Graph* graph, int start) {
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    int queue[graph->V];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        struct AdjListNode* temp = graph->array[current].head;
        while (temp) {
            int adj = temp->dest;
            if (!visited[adj]) {
                visited[adj] = 1;
                queue[rear++] = adj;
            }
            temp = temp->next;
        }
    }
}

// Utility function for DFS traversal
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct AdjListNode* temp = graph->array[v].head;
    while (temp) {
        if (!visited[temp->dest])
            DFSUtil(graph, temp->dest, visited);
        temp = temp->next;
    }
}

// Function for DFS traversal from a given source vertex
void DFS(struct Graph* graph, int start) {
    int visited[graph->V];
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;
    DFSUtil(graph, start, visited);
}

// Main function to test the graph functions
int main() {
    int V = 7;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    printf("Breadth First Traversal of the given graph is: ");
    BFS(graph, 0);
    printf("\n");

    printf("Depth First Traversal of the given graph is: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}

