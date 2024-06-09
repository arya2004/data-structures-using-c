#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H

typedef struct node {
    int data;
    int priority;
    struct node* link;
} Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
    int HighestPriority;
} LinkedListQueue;

LinkedListQueue newLinkedListQueue(int data);
int sizeLinkedListQueue(LinkedListQueue linkedlistqueue);
int rearLinkedListQueue(LinkedListQueue linkedlistqueue);
int frontLinkedListQueue(LinkedListQueue linkedlistqueue);
LinkedListQueue enqueueLinkedListQueue(LinkedListQueue linkedlistqueue, int data, int _priority);
LinkedListQueue dequeueLinkedListQueue(LinkedListQueue linkedlistqueue);
LinkedListQueue dropLinkedListQueue(LinkedListQueue linkedlistqueue);
void displayLinkedListQueue(LinkedListQueue linkedlistqueue);

#endif
