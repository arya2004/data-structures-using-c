#ifndef BFS_ADJLIST_H
#define BFS_ADJLIST_H

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void BFS(int start, int nodes, Node* adjList[]);

#endif
