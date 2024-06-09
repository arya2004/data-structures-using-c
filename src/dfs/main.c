#include <stdio.h>
#include "graph_traversal.h"

/**
 * Main function to demonstrate Depth-First Search (DFS) on a graph.
 */
int main() {
    int vertices = 0; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the adjacency matrix representing the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    fflush(stdin);
    fflush(stdout);
    for (int i = 0; i < vertices; i++) {
        for (int j = i; j < vertices; j++) {
            printf("Is there an edge from vertex %d to vertex %d (1 for Yes, 0 for No): ", i, j);
            scanf("%d", &graph[i][j]);
            fflush(stdin);
            fflush(stdout);

            // Since the graph is undirected, set the corresponding edge from j to i as well
            graph[j][i] = graph[i][j];
        }
    }

    // Perform DFS starting from vertex 0
    printf("DFS traversal starting from vertex 0: ");
    DFS(graph, vertices, 0);

    return 0;
}
