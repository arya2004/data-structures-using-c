#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* previous;
}Node;

typedef struct {
    Node* head;
    int size;
    Node* tail;
}DoubleLinkedList;

DoubleLinkedList newDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
    doublelinkedlist.size = 1;
    doublelinkedlist.head = (Node*) malloc( sizeof(Node));
    doublelinkedlist.head->data = data;
    doublelinkedlist.head->previous = NULL;;
    doublelinkedlist.head->next = NULL;
    doublelinkedlist.tail = doublelinkedlist.head;
    return doublelinkedlist;
    
}

DoubleLinkedList insertEndDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
    doublelinkedlist.tail->next = (Node*) malloc(sizeof(Node));
    doublelinkedlist.tail->next->data = data;
    doublelinkedlist.tail->next->previous = doublelinkedlist.tail;
    doublelinkedlist.tail->next->next = NULL;
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.tail = doublelinkedlist.tail->next;
    return doublelinkedlist;
}

DoubleLinkedList insertBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data){
    doublelinkedlist.head->previous = (Node*)malloc(sizeof(Node));
    doublelinkedlist.size = doublelinkedlist.size + 1;
    doublelinkedlist.head->previous->data = data;
    doublelinkedlist.head->previous->next = doublelinkedlist.head;
    doublelinkedlist.head->previous->previous = NULL;
    doublelinkedlist.head = doublelinkedlist.head->previous;
    return doublelinkedlist;
}

DoubleLinkedList deleteBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    doublelinkedlist.head = doublelinkedlist.head->next;
    free(doublelinkedlist.head->previous);
    doublelinkedlist.head->previous = NULL;
    doublelinkedlist.size = doublelinkedlist.size - 1;
    return doublelinkedlist;
}
DoubleLinkedList deleteEndDoubleLinkedList(DoubleLinkedList doublelinkedlist){
    doublelinkedlist.tail = doublelinkedlist.tail->previous;
    free(doublelinkedlist.tail->next);
    doublelinkedlist.tail->next = NULL;
    doublelinkedlist.size = doublelinkedlist.size -1;
    return doublelinkedlist;
}


DoubleLinkedList dropLinkedList(DoubleLinkedList doublelinkedlist){
    Node* temp = doublelinkedlist.head;
    // for (int i = 1; i < doublelinkedlist.size; i++)
    // {
    //     doublelinkedlist.head = doublelinkedlist.head->next;
    //     free(doublelinkedlist.head->previous);
    // }
    while (temp != NULL)
    {
        temp = temp->next;
        free(doublelinkedlist.head);
        doublelinkedlist.head = temp;
    }
    doublelinkedlist.size = 0;
    return doublelinkedlist;
}


void displayDoubleLinkekdList(DoubleLinkedList doublelinkedlist){
    Node* temp = doublelinkedlist.head;
        printf("\nHEAD");
    for (int i = 0; i < doublelinkedlist.size; i++)
    {
        printf("<->%i", temp->data);
        temp = temp->next;
    }
    printf("<->TAIL");
}