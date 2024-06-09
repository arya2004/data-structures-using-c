#include "stack_linkedlist.h"
#include <stdio.h>

int main() {
    LinkedListStack stack;
    stack = newLinkedListStack(stack, 10);
    stack = pushLinkedListStack(stack, 20);
    stack = pushLinkedListStack(stack, 30);

    displayLinkedListStack(stack);

    stack = popLinkedListStack(stack);
    printf("\nAfter pop operation:");
    displayLinkedListStack(stack);

    int topElement = topLinkedListStack(stack);
    printf("\nTop element of the stack: %d", topElement);

    stack = dropLinkedListStack(stack);

    return 0;
}
