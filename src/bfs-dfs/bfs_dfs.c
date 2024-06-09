#include <stdio.h>
#include <stdlib.h>
#include "queue_array.h"
#include "stack_array.h"
#include "bfs_dfs.h"

/**
 * Breadth-First Search (BFS) algorithm implementation for a graph
 * represented as an adjacency matrix.
 */
void BFS() {
    int g[8][8] = {
        {0,1,1,0,0,0,0,0}, 
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0}, 
        {0,1,1,0,1,0,0,0},
        {0,0,0,1,0,1,1,0}, 
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1}, 
        {0,0,0,0,0,1,1,0}
    };
    int start = 3;
    int visited[8] = {0,0,0,0,0,0,0,0};
    Queue q = initQueue(q, 100);
    q = enqueue(q, start);
    visited[start] = 1;

    while (q.currentSize > 0) {
        int temp = q.element[q.front];
        q = dequeue(q);
        printf("%i ", temp);
        visited[temp] = 1;

        for (int i = 0; i < 8; i++) {
            if (g[temp][i] == 1 && visited[i] == 0) {
                q = enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
}

/**
 * Depth-First Search (DFS) algorithm implementation for a graph
 * represented as an adjacency matrix.
 */
void DFS() {
    int g[8][8] = {
        {0,1,1,0,0,0,0,0}, 
        {1,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,0,0}, 
        {0,1,1,0,1,0,0,0},
        {0,0,0,1,0,1,1,0}, 
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,0,0,1}, 
        {0,0,0,0,0,1,1,0}
    };
    int start = 3;
    int visited[8] = {0,0,0,0,0,0,0,0};
    Stack s = initStack(s, 100);
    s = push(s, start);
    visited[start] = 1;

    while (!isEmpty(s)) {
        int temp = peek(s);
        s = pop(s);
        visited[temp] = 1;
        printf("%i ", temp);

        for (int i = 0; i < 8; i++) {
            if (g[temp][i] == 1 && visited[i] == 0) {
                s = push(s, i);
                visited[i] = 1;
            }
        }
    }
}
