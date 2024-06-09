#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

/**
 * Breadth-First Search (BFS) algorithm implementation for a graph
 * represented as an adjacency matrix.
 *
 * @param start Starting node for BFS
 * @param nodes Total number of nodes in the graph
 * @param adjacencyMatrix Adjacency matrix representing the graph
 */
void BFS(int start, int nodes, int adjacencyMatrix[][MAX_NODES]) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < nodes; ++i) {
            if (adjacencyMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
