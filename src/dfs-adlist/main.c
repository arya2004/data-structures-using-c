#include <stdio.h>
#include "graph_traversal.h"

/**
 * Main function to demonstrate Depth-First Search (DFS) on a graph.
 */
int main() {
    int V = 0;
    int k = 0;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    struct Graph* graph = createGraph(V);

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &k);

    // Input the edges
    for (int i = 0; i < k; i++) {
        int first = 0;
        int second = 0;

        printf("Enter edge from vertex1 to vertex2 separated by space: ");
        scanf("%d %d", &first, &second);
        addEdge(graph, first, second);
    }

    int startingVertex = 0;
    // Input the starting vertex for DFS
    printf("Enter the starting vertex: ");
    scanf("%d", &startingVertex);

    // Perform DFS starting from the given vertex
    printf("DFS traversal starting from vertex %d: ", startingVertex);
    DFS(graph, startingVertex);

    return 0;
}
