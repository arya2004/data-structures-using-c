// linked_list.h - Header file for linked list operations
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define Node structure
typedef struct node {
    int data;
    struct node* link;
} Node;

// Define LinkedList structure
typedef struct {
    Node* head;
    int size;
    Node* tail;
} LinkedList;

// Function prototypes
LinkedList newLinkedList(int data);
int sizeLinkedList(LinkedList linkedlist);
int tailLinkedList(LinkedList linkedlist);
int headLinkedList(LinkedList linkedlist);
LinkedList insertEndLinkedList(LinkedList linkedlist, int data);
LinkedList insertBeginningLinkedList(LinkedList linkedlist, int data);
LinkedList insertAnyLinkedList(LinkedList linkedlist, int data, int position);
LinkedList deleteBeginningLinkedList(LinkedList linkedlist);
LinkedList deleteEndLinkedList(LinkedList linkedlist);
LinkedList deleteAnyLinkedList(LinkedList linkedlist, int position);
LinkedList dropLinkedList(LinkedList linkedlist);
void displayLinkedList(LinkedList linkedlist);

#endif  // LINKED_LIST_H
