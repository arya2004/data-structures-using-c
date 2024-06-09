#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

typedef struct node {
    int data;
    struct node* link;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedListStack;

LinkedListStack newLinkedListStack(LinkedListStack linkedliststack, int data);
int sizeLinkedListStack(LinkedListStack linkedliststack);
int topLinkedListStack(LinkedListStack linkedliststack);
LinkedListStack pushLinkedListStack(LinkedListStack linkedliststack, int data);
LinkedListStack popLinkedListStack(LinkedListStack linkedliststack);
LinkedListStack dropLinkedListStack(LinkedListStack linkedliststack);
void displayLinkedListStack(LinkedListStack linkedliststack);

#endif /* STACK_LINKEDLIST_H */
