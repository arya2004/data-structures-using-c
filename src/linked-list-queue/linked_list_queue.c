#include <stdio.h>
#include <stdlib.h>

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

LinkedListQueue newLinkedListQueue(int data) {
    LinkedListQueue queue;
    queue.head = (Node*)malloc(sizeof(Node));
    queue.tail = queue.head;
    queue.size = 1;
    queue.head->link = NULL;
    queue.head->data = data;
    return queue;
}

int sizeLinkedListQueue(LinkedListQueue queue) {
    return queue.size;
}

int rearLinkedListQueue(LinkedListQueue queue) {
    return queue.tail->data;
}

int frontLinkedListQueue(LinkedListQueue queue) {
    return queue.head->data;
}

LinkedListQueue enqueueLinkedListQueue(LinkedListQueue queue, int data, int priority) {
    queue.tail->link = (Node*)malloc(sizeof(Node));
    queue.tail->link->data = data;
    queue.tail->link->priority = priority;
    queue.tail->link->link = NULL;
    queue.tail = queue.tail->link;
    queue.size++;
    return queue;
}

LinkedListQueue dequeueLinkedListQueue(LinkedListQueue queue) {
    if (queue.size == 0) {
        printf("\nLinked list queue is empty in dequeueLinkedListQueue");
        exit(1);
    }

    Node* temp = queue.head;
    queue.head = queue.head->link;
    queue.size--;
    free(temp);
    return queue;
}

LinkedListQueue dropLinkedListQueue(LinkedListQueue queue) {
    Node* temp = queue.head;
    while (temp != NULL) {
        temp = temp->link;
        free(queue.head);
        queue.head = temp;
    }
    queue.size = 0;
    return queue;
}

void displayLinkedListQueue(LinkedListQueue queue) {
    printf("\nFRONT");
    Node* temp = queue.head;
    while (temp != NULL) {
        printf("->%i", temp->data);
        temp = temp->link;
    }
    printf("<-REAR");
}
