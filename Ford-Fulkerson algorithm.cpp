#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 6

int fordFulkerson(int graph[V][V], int source, int sink) {
    int residualGraph[V][V];
    memcpy(residualGraph, graph, sizeof(residualGraph));
    int parent[V];
    int maxFlow = 0;

    while (true) {
        memset(parent, -1, sizeof(parent));
        bool visited[V] = {false};
        visited[source] = true;
        int queue[V];
        int front = 0, rear = 0;
        queue[rear++] = source;

        while (front < rear) {
            int u = queue[front++];
            for (int v = 0; v < V; v++) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    queue[rear++] = v;
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        if (!visited[sink])
            break;

        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = (residualGraph[u][v] < pathFlow) ? residualGraph[u][v] : pathFlow;
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    int maxFlow = fordFulkerson(graph, source, sink);
    printf("Maximum flow from source to sink is: %d\n", maxFlow);

    return 0;
}

