#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function prototypes
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest, int weight);
void primMST(Graph* graph);

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    Graph* graph = createGraph(numVertices);

    int totalInput;
    printf("Enter the total number of inputs: ");
    scanf("%d", &totalInput);

    printf("Enter starting vertex, ending vertex, and weight for each input:\n");
    for (int i = 0; i < totalInput; i++) {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        addEdge(graph, start, end, weight);
    }

    primMST(graph);

    return 0;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
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
