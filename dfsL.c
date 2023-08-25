#include <stdio.h>
#include <stdlib.h>


#define MAX_VERTICES 100

// linked list
struct Node {
    int vertex;
    struct Node* next;
};

// adj list pointer array
struct Graph {
    struct Node* adjacencyList[MAX_VERTICES];
};

// stack
struct Stack {
    int items[MAX_VERTICES];
    int top;
};

void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// init
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    for (int i = 0; i < V; ++i) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // reverse
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}


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

int main() {
    int V = 0; 
    int k = 0;

  
    printf("enter MAX vertices\n");
    scanf("%i", &V);
    struct Graph* graph = createGraph(V);
    fflush(stdin);
    fflush(stdout);
     printf("enter total edges\n");
    scanf("%i", &k);
    fflush(stdin);
    fflush(stdout);
    for (int i = 0; i < k; i++)
    {
            int first = 0;
            int second = 0;

            printf("enter edge from first to second separated by space\n" );
            scanf("%i %i", &first, &second);
            fflush(stdin);
            fflush(stdout);
             addEdge(graph, first, second);
        
    }
    int startingV = 0;
    printf("enter starting vertec" );
            scanf("%i", &startingV);
            fflush(stdin);
            fflush(stdout);

    printf("dfs  ");
    DFS(graph, startingV);

    return 0;
}
