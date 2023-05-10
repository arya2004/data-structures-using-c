#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include "stack_array.h"
//#include "linkedlist.h"
//#include "queue_array.h"
#include "doublelinkedlist.h"

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
    
    // LinkedList ll = newLinkedList(ll, 44);
    // ll = insertEndLinkedList(ll, 41);
    // ll = insertEndLinkedList(ll, 22);ll = insertEndLinkedList(ll, 102);
    // displayLinkedList(ll);
    // ll = insertBeginningLinkedList(ll, 98);
    // displayLinkedList(ll);
    // ll = deleteBeginningLinkedList(ll);
    // displayLinkedList(ll);
    // ll = dropLinkedList(ll);
    // displayLinkedList(ll);
    // ll = newLinkedList(ll, 88);
    // ll = insertEndLinkedList(ll, 89);
    // ll = insertBeginningLinkedList(ll, 90);
    //     displayLinkedList(ll);
    // printf("\n%i", countLinkedList(ll));


    DoubleLinkedList dll = newDoubleLinkedList(dll, 55);
    dll = insertEndDoubleLinkedList(dll, 23);
    dll = insertEndDoubleLinkedList(dll, 34);
    dll = insertBeginningDoubleLinkedList(dll, 66);
    dll = deleteBeginningDoubleLinkedList(dll);
    dll = deleteEndDoubleLinkedList(dll);
    dll = insertBeginningDoubleLinkedList(dll, 39);
    printf("%i", dll.tail->next);
    dll = dropLinkedList(dll);
    dll = newDoubleLinkedList(dll ,69);
    dll = insertBeginningDoubleLinkedList(dll, 39);
    displayDoubleLinkekdList(dll);
}