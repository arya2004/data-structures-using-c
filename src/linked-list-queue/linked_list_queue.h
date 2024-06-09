#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

typedef struct Node {
    int data;
    int priority;
    struct Node* link;
} Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
    int HighestPriority;
} LinkedListQueue;

LinkedListQueue newLinkedListQueue(int data);
int sizeLinkedListQueue(LinkedListQueue queue);
int rearLinkedListQueue(LinkedListQueue queue);
int frontLinkedListQueue(LinkedListQueue queue);
LinkedListQueue enqueueLinkedListQueue(LinkedListQueue queue, int data, int priority);
LinkedListQueue dequeueLinkedListQueue(LinkedListQueue queue);
LinkedListQueue dropLinkedListQueue(LinkedListQueue queue);
void displayLinkedListQueue(LinkedListQueue queue);

#endif
