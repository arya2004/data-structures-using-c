#include <stdio.h>
#include <stdlib.h>


#define MAX_VERTICES 100


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

int main() {
    int vertices = 0; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("enter vertices\n");
    scanf("%i", &vertices);
    fflush(stdin);
    fflush(stdout);
    for (int i = 0; i < vertices; i++)
    {
        for (int j = i; j < vertices; j++)
        {
            printf("enter edge %i to %i\n",i, j );
            scanf("%i", &graph[i][j]);
            fflush(stdin);
            fflush(stdout);
        }
        
    }
    

    printf("dfs :\n");
    DFS(graph, vertices, 0);

    return 0;
}
