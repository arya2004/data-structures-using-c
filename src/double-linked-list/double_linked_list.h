#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

typedef struct node {
    int data;
    struct node* next;
    struct node* previous;
} Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
} DoubleLinkedList;

DoubleLinkedList newDoubleLinkedList(int data);
int sizeDoubleLinkedList(DoubleLinkedList doublelinkedlist);
int headDoubleLinkedList(DoubleLinkedList doublelinkedlist);
int tailDoubleLinkedList(DoubleLinkedList doublelinkedlist);
DoubleLinkedList insertEndDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data);
DoubleLinkedList insertBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data);
DoubleLinkedList insertAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data, int position);
DoubleLinkedList deleteBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist);
DoubleLinkedList deleteEndDoubleLinkedList(DoubleLinkedList doublelinkedlist);
DoubleLinkedList deleteAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist, int position);
DoubleLinkedList dropDoubleLinkedList(DoubleLinkedList doublelinkedlist);
void displayDoubleLinkedList(DoubleLinkedList doublelinkedlist);

#endif  // DOUBLE_LINKED_LIST_H
