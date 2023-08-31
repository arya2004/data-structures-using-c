#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

int main() {
    int nodes, edges;
    printf("no nodes and edges for bfs Adj list\n ");
    scanf("%d %d", &nodes, &edges);

    Node* adjList[MAX_NODES] = {NULL};
    printf("enter edges i -> j \n");
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = node2;
        newNode->next = adjList[node1];
        adjList[node1] = newNode;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = node1;
        newNode->next = adjList[node2];
        adjList[node2] = newNode;
    }

    int startNode;
    printf("starting:  ");
    scanf("%d", &startNode);

    printf("your BFS \n");
    BFS(startNode, nodes, adjList);

    return 0;
}
