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

LinkedList insertAnyLinkedList(LinkedList linkedlist, int data, int position){
    if (position < 1 || position > linkedlist.size + 1)
    {
        printf("\nposition out of bound in insertAnyLinkedList");
        exit(1);
    }
    else if (position == 1)
    {
        linkedlist = insertBeginningLinkedList(linkedlist, data);
    }
    else if (position == linkedlist.size + 1)
    {
        linkedlist = insertEndLinkedList(linkedlist, data);
    }
    else
    {  
    Node * temp = (Node *)malloc(sizeof(Node));
    Node* ptr = linkedlist.head;
    for (int i = 1; i < position - 1; i++)
    {
        ptr = ptr->link;
    }
    temp->data = data;
    temp->link = ptr->link;
    ptr->link = temp;
    linkedlist.size = linkedlist.size + 1;
    }
    return linkedlist;
}

LinkedList deleteBeginningLinkedList(LinkedList linkedlist){
    Node* temp = linkedlist.head;
    linkedlist.head = linkedlist.head->link;
    linkedlist.size = linkedlist.size - 1;
    free(temp);
    return linkedlist;
}

LinkedList deleteEndLinkedList(LinkedList linkedlist){
    Node* temp = linkedlist.head;
    for (int i = 1; i < linkedlist.size - 1; i++)
    {
        temp = temp->link;
    }
    linkedlist.tail = temp;
    free(temp->link);
    temp->link = NULL;
    linkedlist.size = linkedlist.size - 1;
    return linkedlist;
}

LinkedList deleteAnyLinkedList(LinkedList linkedlist, int position){
    if (position < 1 || position > linkedlist.size )
    {
        printf("\nposition out of bound in deleteAnyLinkedList");
        exit(1);
    }
    else if (position == 1)
    {
        linkedlist = deleteBeginningLinkedList(linkedlist);
    }
    else if (position == linkedlist.size)
    {
        linkedlist = deleteEndLinkedList(linkedlist);
    }
    else
    {  
    Node * current = linkedlist.head;
    Node* previous = linkedlist.head;
    for (int i = 1; i < position - 1; i++)
    {
        previous = previous->link;
    }
    current = previous->link;
    previous->link = current->link;
    free(current);
    linkedlist.size = linkedlist.size -1;
    }
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