#include "queue_operations.h"

// Create a new linked list queue with initial data
LinkedListQueue newLinkedListQueue(LinkedListQueue linkedlistqueue, int data)
{
    linkedlistqueue.head = (Node*)malloc(sizeof(Node));
    linkedlistqueue.tail = linkedlistqueue.head;
    linkedlistqueue.size = 1;
    linkedlistqueue.head->link = NULL;
    linkedlistqueue.head->data = data;
    return linkedlistqueue;
}

// Get the size of the linked list queue
int sizeLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    return linkedlistqueue.size;
}

// Get the data at the rear of the linked list queue
int rearLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    return linkedlistqueue.tail->data;
}

// Get the data at the front of the linked list queue
int frontLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    return linkedlistqueue.head->data;
}

// Enqueue an element into the linked list queue
LinkedListQueue enqueueLinkedListQueue(LinkedListQueue linkedlistqueue, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    linkedlistqueue.tail->link = temp;
    linkedlistqueue.tail->link->data = data;
    linkedlistqueue.tail->link->link = NULL;
    linkedlistqueue.tail = linkedlistqueue.tail->link;
    linkedlistqueue.size = linkedlistqueue.size + 1;
    return linkedlistqueue;
}

// Dequeue an element from the linked list queue
LinkedListQueue dequeueLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    if (linkedlistqueue.size == 0)
    {
        printf("\nlinked list queue is empty in dequeueLinkedListQueue");
        exit(1);
    }
    Node* temp = linkedlistqueue.head;
    linkedlistqueue.head = linkedlistqueue.head->link;
    linkedlistqueue.size = linkedlistqueue.size - 1;
    free(temp);
    return linkedlistqueue;
}

// Drop the linked list queue and free memory
LinkedListQueue dropLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    Node * temp = linkedlistqueue.head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(linkedlistqueue.head);
        linkedlistqueue.head = temp;
    }
    linkedlistqueue.size = 0;
    return linkedlistqueue;
}

// Display the linked list queue
void displayLinkedListQueue(LinkedListQueue linkedlistqueue)
{
    printf("\nFRONT");
    LinkedListQueue temp = linkedlistqueue;
    for (int i = 0; i < linkedlistqueue.size; i++)
    {
        printf("->%i", temp.head->data);
        temp.head = temp.head->link;
    }
    printf("<-REAR");
}
