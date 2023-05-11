#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node* link;
}Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
}LinkedListQueue;

LinkedListQueue newLinkedListQueue(LinkedListQueue LinkedListQueue, int data)
{
    LinkedListQueue.head = (Node*)malloc(sizeof(Node));
    LinkedListQueue.tail = LinkedListQueue.head;
    LinkedListQueue.size = 1;
    LinkedListQueue.head->link = NULL;
    LinkedListQueue.head->data = data;
    return LinkedListQueue;
}

int sizeLinkedListQueue(LinkedListQueue LinkedListQueue){
    return LinkedListQueue.size;
}

int rearLinkedListQueue(LinkedListQueue LinkedListQueue){
    return LinkedListQueue.tail->data;
}
int frontLinkedListQueue(LinkedListQueue LinkedListQueue){
    return LinkedListQueue.head->data;
}

LinkedListQueue enqueueLinkedListQueue(LinkedListQueue LinkedListQueue, int data)
{
    LinkedListQueue.tail->link = (Node*)malloc(sizeof(Node));
    LinkedListQueue.tail->link->data = data;
    LinkedListQueue.tail->link->link = NULL;
    LinkedListQueue.tail = LinkedListQueue.tail->link;
    LinkedListQueue.size = LinkedListQueue.size + 1;  
    return LinkedListQueue;
}

LinkedListQueue dequeueLinkedListQueue(LinkedListQueue LinkedListQueue)
{
    Node* temp = LinkedListQueue.head;
    LinkedListQueue.head = LinkedListQueue.head->link;
    LinkedListQueue.size = LinkedListQueue.size - 1;
    free(temp);
    return LinkedListQueue;
}


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