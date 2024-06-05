#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

#define MAX_VERTICES 1000 

struct AdjListNode { 
    int dest; 
    struct AdjListNode* next; 
}; 

struct AdjList { 
    struct AdjListNode* head; 
}; 

struct Graph { 
    int V; 
    struct AdjList* array; 
}; 

struct AdjListNode* newAdjListNode(int dest) { 
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 

struct Graph* createGraph(int V) { 
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); 
    graph->V = V; 
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList)); 
    for (int i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
    return graph; 
} 

void addEdge(struct Graph* graph, int src, int dest) { 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
} 

void topologicalSort(struct Graph* graph) { 
    int V = graph->V; 
    int* inDegree = (int*)calloc(V, sizeof(int)); 
    
    for (int v = 0; v < V; ++v) { 
        struct AdjListNode* temp = graph->array[v].head; 
        while (temp) { 
            ++inDegree[temp->dest]; 
            temp = temp->next; 
        } 
    } 
    
    int* queue = (int*)malloc(V * sizeof(int)); 
    int front = 0, rear = 0; 
    
    for (int v = 0; v < V; ++v) { 
        if (inDegree[v] == 0) 
            queue[rear++] = v; 
    } 
    
    int counter = 0; 
    int* topologicalOrder = (int*)malloc(V * sizeof(int)); 
    
    while (front != rear) { 
        int u = queue[front++]; 
        topologicalOrder[counter++] = u; 
        struct AdjListNode* temp = graph->array[u].head; 
        
        while (temp) { 
            --inDegree[temp->dest]; 
            if (inDegree[temp->dest] == 0) 
                queue[rear++] = temp->dest; 
            temp = temp->next; 
        } 
    } 
    
    if (counter != V) { 
        printf("Graph contains a cycle!\n"); 
        return; 
    } 
    
    printf("Topological Sorting: "); 
    for (int i = 0; i < V; ++i) 
        printf("%d ", topologicalOrder[i]); 
    printf("\n"); 
    
    free(inDegree); 
    free(queue); 
    free(topologicalOrder); 
} 

int main() { 
    struct Graph* graph = createGraph(6); 
    addEdge(graph, 5, 2); 
    addEdge(graph, 5, 0); 
    addEdge(graph, 4, 0); 
    addEdge(graph, 4, 1); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 1); 
    topologicalSort(graph); 
    return 0; 
} 

