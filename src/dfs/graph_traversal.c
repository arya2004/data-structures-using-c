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
 * Performs Depth-First Search (DFS) on the graph starting from a given vertex.
 *
 * @param graph Adjacency matrix representing the graph.
 * @param vertices Number of vertices in the graph.
 * @param startVertex The starting vertex for DFS.
 */
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    int visited[MAX_VERTICES] = {0};

    push(stack, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                push(stack, i);
                visited[i] = 1;
            }
        }
    }
    free(stack);
}
