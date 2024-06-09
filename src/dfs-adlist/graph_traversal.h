#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#define MAX_VERTICES 100

// Definition of a Node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Definition of a Graph with an adjacency list
struct Graph {
    struct Node* adjacencyList[MAX_VERTICES];
};

// Definition of a Stack
struct Stack {
    int items[MAX_VERTICES];
    int top;
};

// Function declarations
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int startVertex);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);

#endif
