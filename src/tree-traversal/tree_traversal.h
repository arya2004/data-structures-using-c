#ifndef TREE_TRAVERSAL_H
#define TREE_TRAVERSAL_H

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    int size;
    int top;
    Node **array;
} Stack;

Node* newNode(int data);
Stack* createStack(int size);
int isFull(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, Node* node);
Node* pop(Stack* stack);
Node* peek(Stack* stack);
void postorder(Node* root);

#endif
