#include <stdio.h>
#include <stdlib.h>
#include "graph_traversal.h"

/**
 * Pushes an item onto the stack.
 *
 * @param stack Pointer to the Stack.
 * @param item The item to be pushed.
 */
void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

/**
 * Pops an item from the stack.
 *
 * @param stack Pointer to the Stack.
 * @return The popped item.
 */
int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

/**
 * Checks if the stack is empty.
 *
 * @param stack Pointer to the Stack.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

/**
 * Creates a graph with V vertices.
 *
 * @param V Number of vertices.
 * @return Pointer to the created Graph.
 */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < V; ++i) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

/**
 * Adds an edge to the graph.
 *
 * @param graph Pointer to the Graph.
 * @param src Source vertex.
 * @param dest Destination vertex.
 */
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

/**
 * Performs Depth-First Search (DFS) on the graph starting from a given vertex.
 *
 * @param graph Pointer to the Graph.
 * @param startVertex The starting vertex for DFS.
 */
void DFS(struct Graph* graph, int startVertex) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    int visited[MAX_VERTICES] = {0};

    push(stack, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjacencyList[currentVertex];
        while (temp) {
            int adjacentVertex = temp->vertex;
            if (!visited[adjacentVertex]) {
                push(stack, adjacentVertex);
                visited[adjacentVertex] = 1;
            }
            temp = temp->next;
        }
    }
    free(stack);
}
