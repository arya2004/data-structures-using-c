#ifndef PRIM_MST_H
#define PRIM_MST_H

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* vertices[MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest, int weight);
void primMST(Graph* graph);

#endif
