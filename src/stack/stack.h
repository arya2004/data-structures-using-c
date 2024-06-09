#ifndef STACK_H
#define STACK_H

typedef struct {
    int top;
    int size;
    int *element;
} Stack;

Stack initStack(Stack stack, int size);
int isFull(Stack stack);
int isEmpty(Stack stack);
int peek(Stack stack);
Stack push(Stack stack, int x);
Stack pop(Stack stack);
void displayStack(Stack stack);

#endif /* STACK_H */
