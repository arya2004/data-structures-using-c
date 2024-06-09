#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int size;
    int *element;
} Stack;

// Function to initialize the stack
Stack initStack(Stack stack, int size) {
    stack.size = size;
    stack.top = -1;
    stack.element = (int *)malloc(sizeof(int) * size);
    return stack;
}

// Function to check if the stack is full
int isFull(Stack stack) {
    return stack.top == stack.size - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack stack) {
    return stack.top == -1;
}

// Function to peek the top element of the stack
int peek(Stack stack) {
    if (!isEmpty(stack)) {
        return stack.element[stack.top];
    }
    printf("\nStack is empty, cannot peek.");
    exit(1);
}

// Function to push an element onto the stack
Stack push(Stack stack, int x) {
    if (!isFull(stack)) {
        stack.top++;
        stack.element[stack.top] = x;
    } else {
        printf("\nStack is full, cannot push.");
        exit(1);
    }
    return stack;
}

// Function to pop an element from the stack
Stack pop(Stack stack) {
    if (!isEmpty(stack)) {
        stack.top--;
    } else {
        printf("\nStack is empty, cannot pop.");
        exit(1);
    }
    return stack;
}

// Function to display the elements of the stack
void displayStack(Stack stack) {
    if (!isEmpty(stack)) {
        printf("\nStack elements: ");
        for (int i = 0; i <= stack.top; i++) {
            printf("%i ", stack.element[i]);
        }
    } else {
        printf("\nStack is empty.");
    }
}

int main() {
    Stack stack;
    stack = initStack(stack, 5);
    
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);

    displayStack(stack);

    stack = pop(stack);
    printf("\nAfter pop operation:");
    displayStack(stack);

    int topElement = peek(stack);
    printf("\nTop element of the stack: %d", topElement);

    return 0;
}
