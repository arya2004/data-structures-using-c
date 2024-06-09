#include <stdio.h>
#include <stdlib.h>
#include "bfs_adjlist.h"

/**
 * Main function to demonstrate BFS algorithm using an adjacency list.
 */
int main() {
    int nodes, edges;

    // Input the number of nodes and edges
    printf("Enter the number of nodes and edges for BFS using adjacency list:\n");
    scanf("%d %d", &nodes, &edges);

    Node* adjList[MAX_NODES] = {NULL};

    // Input the edges of the graph
    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        // Add edge node1 -> node2
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = node2;
        newNode->next = adjList[node1];
        adjList[node1] = newNode;

        // Add edge node2 -> node1 (for undirected graph)
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = node1;
        newNode->next = adjList[node2];
        adjList[node2] = newNode;
    }

    int startNode;

    // Input the starting node for BFS
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    // Perform BFS starting from the given node
    printf("BFS traversal starting from node %d:\n", startNode);
    BFS(startNode, nodes, adjList);

    return 0;
}
