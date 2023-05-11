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
}LinkedListStack;

LinkedListStack newLinkedListStack(LinkedListStack linkedliststack, int data)
{
    linkedliststack.head = (Node*)malloc(sizeof(Node));
    linkedliststack.size = 1;
    linkedliststack.head->link = NULL;
    linkedliststack.head->data = data;
    return linkedliststack;
}

int sizeLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.size;
}

int topLinkedListStack(LinkedListStack linkedliststack)
{
    return linkedliststack.head->data;
}

LinkedListStack pushLinkedListStack(LinkedListStack linkedliststack, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = linkedliststack.head;
    linkedliststack.size = linkedliststack.size + 1;
    linkedliststack.head = temp;
    return linkedliststack;
}

LinkedListStack popLinkedListStack(LinkedListStack linkedliststack)
{
    Node* temp = linkedliststack.head;
    linkedliststack.head = linkedliststack.head->link;
    linkedliststack.size = linkedliststack.size - 1;
    free(temp);
    return linkedliststack;
}

LinkedListStack dropLinkedListStack(LinkedListStack linkedliststack)
{
    Node * temp = linkedliststack.head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(linkedliststack.head);
        linkedliststack.head = temp;
    }
    linkedliststack.size = 0;
    return linkedliststack;
}

void displayLinkedListStack(LinkedListStack linkedliststack)
{
    printf("\nTOP");
    LinkedListStack temp = linkedliststack;
    for (int i = 0; i < linkedliststack.size; i++)
    {
        printf("->%i", temp.head->data);
        temp.head = temp.head->link;
    }
    
}