#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

struct node {
    int data;
    struct node* next;
    struct node* previous;
};

typedef struct {
    struct node* head;
    int size;
    struct node* tail;
}DoubleLinkedList;

