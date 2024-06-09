#ifndef QUEUE_OPERATIONS_H
#define QUEUE_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct node {
    int data;
    struct node* link;
} Node;

// Define LinkedListQueue structure
typedef struct {
    Node* head;
    int size;
    Node* tail;
} LinkedListQueue;

// Function prototypes
LinkedListQueue newLinkedListQueue(LinkedListQueue linkedlistqueue, int data);
int sizeLinkedListQueue(LinkedListQueue linkedlistqueue);
int rearLinkedListQueue(LinkedListQueue linkedlistqueue);
int frontLinkedListQueue(LinkedListQueue linkedlistqueue);
LinkedListQueue enqueueLinkedListQueue(LinkedListQueue linkedlistqueue, int data);
LinkedListQueue dequeueLinkedListQueue(LinkedListQueue linkedlistqueue);
LinkedListQueue dropLinkedListQueue(LinkedListQueue linkedlistqueue);
void displayLinkedListQueue(LinkedListQueue linkedlistqueue);

#endif /* QUEUE_OPERATIONS_H */
