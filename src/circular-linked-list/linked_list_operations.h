#ifndef LINKED_LIST_OPERATIONS_H
#define LINKED_LIST_OPERATIONS_H

typedef struct node {
    int data;
    struct node* link;
} Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
} LinkedList;

LinkedList dropLinkedList(LinkedList linkedlist);
LinkedList newLinkedList(LinkedList linkedlist, int data);
int sizeLinkedList(LinkedList linkedlist);
int tailLinkedList(LinkedList linkedlist);
int headLinkedList(LinkedList linkedlist);
LinkedList insertEndLinkedList(LinkedList linkedlist, int data);
LinkedList insertBeginningLinkedList(LinkedList linkedlist, int data);
LinkedList insertAnyLinkedList(LinkedList linkedlist, int data, int position);
LinkedList deleteBeginningLinkedList(LinkedList linkedlist);
LinkedList deleteEndLinkedList(LinkedList linkedlist);
LinkedList deleteAnyLinkedList(LinkedList linkedlist, int position);
void displayLinkedList(LinkedList linkedlist);

#endif
