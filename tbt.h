#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct stack
{
    Node* T;
    struct stack * next;
}Stack;

typedef struct queue
{
    Node*t;
    struct queue*F,*R;
}Queue;
//add delete queue, insert queue

void push(Node* root, Stack** top)
{
    Stack* temp;
    temp = (Stack*)malloc(sizeof(Stack));
    temp->T = root;
    temp->next = *top;
    (*top) = temp;
}

Node* pop(Stack**top)
{
    if(*top == NULL)
    {
        return NULL;
    }
    Stack* temp = *top;
    (*top) = temp->next;
    Node* temp_hold = temp->T;
    free(temp);
    return temp_hold;
}

// void Enqueue(root, &R)
// {
//     while (!EmptyQueue(&F))
//     {
//         /* code */
//     }
    
// }

