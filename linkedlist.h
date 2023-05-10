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
}LinkedList;

LinkedList newLinkedList(LinkedList linkedlist, int data){
    linkedlist.head = (Node*)malloc(sizeof(Node));
    linkedlist.tail = linkedlist.head;
    linkedlist.size = 1;
    linkedlist.head->link = NULL;
    linkedlist.head->data = data;
    return linkedlist;
}

int sizeLinkedList(LinkedList linkedlist){
    return linkedlist.size;
}

int tailLinkedList(LinkedList linkedlist){
    return linkedlist.tail->data;
}
int headLinkedList(LinkedList linkedlist){
    return linkedlist.head->data;
}

LinkedList insertEndLinkedList(LinkedList linkedlist, int data){
    linkedlist.tail->link = (Node*)malloc(sizeof(Node));
    linkedlist.tail->link->data = data;
    linkedlist.tail->link->link = NULL;
    linkedlist.tail = linkedlist.tail->link;
    linkedlist.size = linkedlist.size + 1;  
    return linkedlist;
}

LinkedList insertBeginningLinkedList(LinkedList linkedlist, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = linkedlist.head;
    linkedlist.size = linkedlist.size + 1;
    linkedlist.head = temp;
    return linkedlist;
}

LinkedList deleteBeginningLinkedList(LinkedList linkedlist){
    Node* temp = linkedlist.head;
    linkedlist.head = linkedlist.head->link;
    linkedlist.size = linkedlist.size - 1;
    free(temp);
    return linkedlist;
}

LinkedList dropLinkedList(LinkedList linkedlist){
    Node * temp = linkedlist.head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(linkedlist.head);
        linkedlist.head = temp;
    }
    linkedlist.size = 0;
    return linkedlist;
}

void displayLinkedList(LinkedList linkedlist){
    printf("\nHEAD");
    LinkedList temp = linkedlist;
    for (int i = 0; i < linkedlist.size; i++)
    {
        printf("->%i", temp.head->data);
        temp.head = temp.head->link;
    }
    printf("<-TAIL");
}