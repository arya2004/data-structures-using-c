#include "LinkedListQueue.h"
#include <stdio.h>
#include <stdlib.h>

LinkedListQueue newLinkedListQueue(int data) {
    LinkedListQueue linkedlistqueue;
    linkedlistqueue.head = (Node*)malloc(sizeof(Node));
    linkedlistqueue.tail = linkedlistqueue.head;
    linkedlistqueue.size = 1;
    linkedlistqueue.head->link = NULL;
    linkedlistqueue.head->data = data;
    return linkedlistqueue;
}

int sizeLinkedListQueue(LinkedListQueue linkedlistqueue) {
    return linkedlistqueue.size;
}

int rearLinkedListQueue(LinkedListQueue linkedlistqueue) {
    return linkedlistqueue.tail->data;
}

int frontLinkedListQueue(LinkedListQueue linkedlistqueue) {
    return linkedlistqueue.head->data;
}

LinkedListQueue enqueueLinkedListQueue(LinkedListQueue linkedlistqueue, int data, int _priority) {
    linkedlistqueue.tail->link = (Node*)malloc(sizeof(Node));
    linkedlistqueue.tail->link->data = data;
    linkedlistqueue.tail->link->priority = _priority;
    linkedlistqueue.tail->link->link = NULL;
    linkedlistqueue.tail = linkedlistqueue.tail->link;
    linkedlistqueue.size++;
    return linkedlistqueue;
}

LinkedListQueue dequeueLinkedListQueue(LinkedListQueue linkedlistqueue) {
    int _secondHighestPriority = -1;
    if (linkedlistqueue.size == 0) {
        printf("\nlinked list queue is empty in dequeueLinkedListQueue");
        exit(1);
    }
    Node* temp = linkedlistqueue.head;
    for (int i = 1; i < linkedlistqueue.size; i++) {
        if (temp->priority >= _secondHighestPriority && _secondHighestPriority <= linkedlistqueue.HighestPriority) {
            _secondHighestPriority = temp->priority;
        }
        temp = temp->link;
    }
    Node* temp = linkedlistqueue.head;
    linkedlistqueue.head = linkedlistqueue.head->link;
    linkedlistqueue.size--;
    free(temp);
    return linkedlistqueue;
}

LinkedListQueue dropLinkedListQueue(LinkedListQueue linkedlistqueue) {
    Node* temp = linkedlistqueue.head;
    while (temp != NULL) {
        temp = temp->link;
        free(linkedlistqueue.head);
        linkedlistqueue.head = temp;
    }
    linkedlistqueue.size = 0;
    return linkedlistqueue;
}

void displayLinkedListQueue(LinkedListQueue linkedlistqueue) {
    printf("\nFRONT");
    LinkedListQueue temp = linkedlistqueue;
    for (int i = 0; i < linkedlistqueue.size; i++) {
        printf("->%i", temp.head->data);
        temp.head = temp.head->link;
    }
    printf("<-REAR");
}
