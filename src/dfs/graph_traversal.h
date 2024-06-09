#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#define MAX_VERTICES 100

// Definition of a Stack
struct Stack {
    int items[MAX_VERTICES];
    int top;
};

// Function declarations
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int isEmpty(struct Stack* stack);
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex);

#endif
