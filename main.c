#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include "stack_array.h"
#include "linkedlist.h"
//#include "queue_array.h"


int main()
{   
    
    // Stack stack = initStack(stack, 5);
    // stack = push(stack, 7);stack = push(stack, 3);stack = push(stack, 22);stack = push(stack, 10);
    // stack = displayStack(stack);
    // stack = pop(stack);
    //  stack = push(stack, 88);
    // stack = push(stack, 11);
    // // stack = push(stack, 33);
    // printf("\n%i", peek(stack));
    // stack = displayStack(stack);
    LinkedList ll = initLinkedList(ll, 44);
    ll = insertEnd(ll, 41);
    ll = insertEnd(ll, 22);ll = insertEnd(ll, 102);
    displayLinkedList(ll);
    ll = insertBeginning(ll, 98);
    displayLinkedList(ll);
    printf("\n%i", countLinkedList(ll));
}