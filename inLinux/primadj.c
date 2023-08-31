#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>


#define MAX_VERTICES 100
#define INF 9999999

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* vertices[MAX_VERTICES];
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; ++i) {
        graph->vertices[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = graph->vertices[src];
    graph->vertices[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->weight = weight;
    newNode->next = graph->vertices[dest];
    graph->vertices[dest] = newNode;
}

void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int parent[numVertices];
    int key[numVertices];
    bool inMST[numVertices];

    for (int v = 0; v < numVertices; ++v) {
        parent[v] = -1;
        key[v] = INF;
        inMST[v] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        for (int v = 0; v < numVertices; ++v) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;

        Node* temp = graph->vertices[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; ++i) {
        printf("%d - %d \t%d\n", parent[i], i, key[i]);
    }
}

int main() {
    int numVertices = 9;
     printf("enter total vertice\n");
     scanf("%i", &numVertices);
    Graph* graph = createGraph(numVertices);

    int total_input = 0;
     printf("enter total inputs\n"); fflush(stdin);
      fflush(stdout);

     scanf("%i", &total_input);
      fflush(stdin);
      fflush(stdout);
      printf("starting v ending v and weight\n");
      fflush(stdin);
      fflush(stdout);
    for (int i = 0; i < total_input; i++) {
         fflush(stdin);
      fflush(stdout);
        printf("enter input %i\n", i);
        int t = 0;
        int y = 0;
        int u = 0;
            scanf("%i %i %i", &t, &y, &u);
            addEdge(graph, t, y, u);
       
    }


    // addEdge(graph, 0, 1, 7);
    // addEdge(graph, 1, 3, 6);
    // addEdge(graph, 0, 2, 3);
    // addEdge(graph, 2, 3, 6);
    // addEdge(graph, 0, 5, 9);
    // addEdge(graph, 5, 2, 8);
    // addEdge(graph, 2, 4, 4);
    // addEdge(graph, 3, 4, 2);
    // addEdge(graph, 5, 6, 4);
    // addEdge(graph, 5, 7, 3);
    // addEdge(graph, 6, 7, 7);
    // addEdge(graph, 4, 8, 6);
    // addEdge(graph, 7, 8, 3);
    // addEdge(graph, 7, 6, 7);
    // addEdge(graph, 6, 8, 6);

    primMST(graph);

    return 0;
}
