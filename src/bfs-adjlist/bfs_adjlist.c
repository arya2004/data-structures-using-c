#include <stdio.h>
#include <stdlib.h>
#include "bfs_adjlist.h"

/**
 * Breadth-First Search (BFS) algorithm implementation for a graph
 * represented as an adjacency list.
 *
 * @param start Starting node for BFS
 * @param nodes Total number of nodes in the graph
 * @param adjList Adjacency list representing the graph
 */
void BFS(int start, int nodes, Node* adjList[]) {
    int visited[MAX_NODES] = {0};
    Node* queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = adjList[start];

    while (front != rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);

        while (current != NULL) {
            if (!visited[current->data]) {
                visited[current->data] = 1;
                queue[rear++] = adjList[current->data];
            }
            current = current->next;
        }
    }
}
