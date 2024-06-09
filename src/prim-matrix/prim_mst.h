#ifndef PRIM_MST_H
#define PRIM_MST_H

#include <stdbool.h>

#define INF 9999
#define V 5

int findMinKey(int key[], bool mstSet[]);
void printMST(int parent[], int graph[V][V]);
void primMST(int graph[V][V]);

#endif
