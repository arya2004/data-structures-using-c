#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct _Node{
    int data;
    struct _Node* next;
    struct _Node* previous;

}Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
}LinkedListDOubleEndedQueue;

LinkedListDOubleEndedQueue dropDoubleQueue(LinkedListDOubleEndedQueue);

int SizeDoubleEndQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue)
{
    return _linkedListDOubleEndedQueue.size;
}

int HeadDoubleEndQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue)
{
    return _linkedListDOubleEndedQueue.head->data;
}
int TailDoubleEndQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue)
{
    return _linkedListDOubleEndedQueue.tail->data;
}

LinkedListDOubleEndedQueue InitLinkedListDOubleEndedQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue, int data)
{
    _linkedListDOubleEndedQueue.head = (Node*) malloc(sizeof(Node));
    _linkedListDOubleEndedQueue.tail = _linkedListDOubleEndedQueue.head;
    _linkedListDOubleEndedQueue.size = 1;
    _linkedListDOubleEndedQueue.head->data = data;
    _linkedListDOubleEndedQueue.head->next = NULL;
    _linkedListDOubleEndedQueue.head->previous = NULL;
    return _linkedListDOubleEndedQueue;
}

LinkedListDOubleEndedQueue EnqueueFront(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue, int data)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->next = _linkedListDOubleEndedQueue.head;
    temp->previous = NULL;
    temp->data = data;
    _linkedListDOubleEndedQueue.head->previous = temp;
    _linkedListDOubleEndedQueue.head = temp;
    _linkedListDOubleEndedQueue.size = _linkedListDOubleEndedQueue.size + 1;
    return _linkedListDOubleEndedQueue;
}

LinkedListDOubleEndedQueue DequeueRear(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue)
{   
    if (_linkedListDOubleEndedQueue.size == 0)
    {
        printf("\nlinked list queue is empty in dequeueLinkedListQueue");
        exit(1);
    }
    if (_linkedListDOubleEndedQueue.size == 1)
    {
        _linkedListDOubleEndedQueue = dropDoubleQueue(_linkedListDOubleEndedQueue);
        return _linkedListDOubleEndedQueue;
    }
    _linkedListDOubleEndedQueue.tail = _linkedListDOubleEndedQueue.tail->previous;
    _linkedListDOubleEndedQueue.size = _linkedListDOubleEndedQueue.size -1;
    free(_linkedListDOubleEndedQueue.tail->next);
    return _linkedListDOubleEndedQueue;
}

LinkedListDOubleEndedQueue EnqueueRear(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue, int data)
{
    _linkedListDOubleEndedQueue.tail->next = (Node*)malloc(sizeof(Node));
    _linkedListDOubleEndedQueue.tail->next->previous = _linkedListDOubleEndedQueue.tail;
    _linkedListDOubleEndedQueue.tail = _linkedListDOubleEndedQueue.tail->next;
    _linkedListDOubleEndedQueue.tail->next = NULL;
    _linkedListDOubleEndedQueue.tail->data = data;
    _linkedListDOubleEndedQueue.size = _linkedListDOubleEndedQueue.size + 1;
    return _linkedListDOubleEndedQueue;
}

LinkedListDOubleEndedQueue DequeueFront(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue)
{   
    if (_linkedListDOubleEndedQueue.size == 0)
    {
        printf("\nlinked list queue is empty in dequeueLinkedListQueue");
        exit(1);
    }
    if (_linkedListDOubleEndedQueue.size == 1)
    {
        _linkedListDOubleEndedQueue = dropDoubleQueue(_linkedListDOubleEndedQueue);
        return _linkedListDOubleEndedQueue;
    }
    _linkedListDOubleEndedQueue.head = _linkedListDOubleEndedQueue.head->next;
    free(_linkedListDOubleEndedQueue.head->previous);
    _linkedListDOubleEndedQueue.size = _linkedListDOubleEndedQueue.size -1;
    _linkedListDOubleEndedQueue.head->previous = NULL;
    return _linkedListDOubleEndedQueue;
}

void displayDoubleEndedQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue){
    Node* temp = _linkedListDOubleEndedQueue.head;
        printf("\nFront");
    for (int i = 0; i < _linkedListDOubleEndedQueue.size; i++)
    {
        printf("<->%i", temp->data);
        temp = temp->next;
    }
    printf("<->Rear");
}

LinkedListDOubleEndedQueue dropDoubleQueue(LinkedListDOubleEndedQueue _linkedListDOubleEndedQueue){
    free(_linkedListDOubleEndedQueue.head);
    _linkedListDOubleEndedQueue.head = NULL;
    _linkedListDOubleEndedQueue.tail = NULL;
    _linkedListDOubleEndedQueue.size = 0;
    return _linkedListDOubleEndedQueue;
}