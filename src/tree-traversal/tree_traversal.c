#include <stdio.h>
#include <stdlib.h>
#include "tree_traversal.h"

/**
 * Creates a new tree node with the given data.
 *
 * @param data The data for the new node.
 * @return Pointer to the new node.
 */
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/**
 * Creates a stack of given size.
 *
 * @param size The maximum size of the stack.
 * @return Pointer to the created stack.
 */
Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (Node**) malloc(stack->size * sizeof(Node*));
    return stack;
}

/**
 * Checks if the stack is full.
 *
 * @param stack The stack to be checked.
 * @return 1 if the stack is full, 0 otherwise.
 */
int isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

/**
 * Checks if the stack is empty.
 *
 * @param stack The stack to be checked.
 * @return 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

/**
 * Pushes a node onto the stack.
 *
 * @param stack The stack to push the node onto.
 * @param node The node to be pushed.
 */
void push(Stack* stack, Node* node) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

/**
 * Pops a node from the stack.
 *
 * @param stack The stack to pop the node from.
 * @return The popped node.
 */
Node* pop(Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

/**
 * Peeks at the top node of the stack without popping it.
 *
 * @param stack The stack to peek at.
 * @return The top node of the stack.
 */
Node* peek(Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

/**
 * Performs a postorder traversal of the tree using an iterative approach.
 *
 * @param root The root node of the tree.
 */
void postorder(Node* root) {
    if (root == NULL)
        return;

    Stack* stack = createStack(MAX_SIZE);
    do {
        while (root) {
            if (root->right)
                push(stack, root->right);
            push(stack, root);
            root = root->left;
        }

        root = pop(stack);

        if (root->right && peek(stack) == root->right) {
            pop(stack);
            push(stack, root);
            root = root->right;
        } else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}
