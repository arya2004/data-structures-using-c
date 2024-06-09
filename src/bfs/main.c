#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

/**
 * Main function to demonstrate BFS algorithm.
 */
int main() {
    int nodes, edges;

    // Input the number of nodes and edges
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};

    // Input the edges of the graph
    printf("Enter the edges (node1 node2): \n");
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = 1;
    }

    int startNode;

    // Input the starting node for BFS
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    // Perform BFS starting from the given node
    printf("BFS traversal starting from node %d: ", startNode);
    BFS(startNode, nodes, adjacencyMatrix);

    return 0;
}
