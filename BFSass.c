#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

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

int main() {
    int nodes, edges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};
    printf("Enter the edges (node1 node2): \n");
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        adjacencyMatrix[node1][node2] = adjacencyMatrix[node2][node1] = 1;
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    BFS(startNode, nodes, adjacencyMatrix);

    return 0;
}
