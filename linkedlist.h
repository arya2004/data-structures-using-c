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

LinkedList initLinkedList(LinkedList linkedlist, int data){
    linkedlist.head = (Node*)malloc(sizeof(Node));
    linkedlist.tail = linkedlist.head;
    linkedlist.size = 1;
    linkedlist.head->link = NULL;
    linkedlist.head->data = data;
    return linkedlist;
}

int countLinkedList(LinkedList linkedlist){
    return linkedlist.size;
}

LinkedList insertEnd(LinkedList linkedlist, int data){
    linkedlist.tail->link = (Node*)malloc(sizeof(Node));
    linkedlist.tail->link->data = data;
    linkedlist.tail->link->link = NULL;
    linkedlist.tail = linkedlist.tail->link;
    linkedlist.size = linkedlist.size + 1;  
    return linkedlist;
}

LinkedList insertBeginning(LinkedList linkedlist, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = linkedlist.head;
    linkedlist.size = linkedlist.size + 1;
    linkedlist.head = temp;
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