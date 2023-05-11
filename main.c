#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include "stack_array.h"
#include "linkedlist.h"
//#include "queue_array.h"
//#include "doublelinkedlist.h"

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
    
    LinkedList ll = newLinkedList(ll, 44);
    ll = insertEndLinkedList(ll, 41);
    ll = insertEndLinkedList(ll, 22);
    ll = insertEndLinkedList(ll, 102);
    displayLinkedList(ll);
    ll = insertBeginningLinkedList(ll, 98);
    displayLinkedList(ll);
    ll = insertAnyLinkedList(ll, 1000, 3);
   
    displayLinkedList(ll);
    ll = insertAnyLinkedList(ll, 1001, 1);
   displayLinkedList(ll);
    ll = insertEndLinkedList(ll, 89);
    ll = insertBeginningLinkedList(ll, 90);
        //displayLinkedList(ll);
    printf("\n%i", sizeLinkedList(ll));
    printf("\n%i", ll.tail->data);
displayLinkedList(ll);
  ll = deleteAnyLinkedList(ll, 1);
displayLinkedList(ll);

    // DoubleLinkedList dll = newDoubleLinkedList(dll, 55);
    // dll = insertEndDoubleLinkedList(dll, 23);
    // dll = insertEndDoubleLinkedList(dll, 34);
    // dll = insertBeginningDoubleLinkedList(dll, 66);
   
    // dll = insertBeginningDoubleLinkedList(dll, 36);
    
    
    // dll = insertBeginningDoubleLinkedList(dll, 39);
    
    // displayDoubleLinkekdList(dll);
    // dll = deleteAnyDoubleLinkedList(dll,4);
    // displayDoubleLinkekdList(dll);

  //   Queue q = initQueue(q, 4);
  //   q = enqueue(q, 22);
  //   q = enqueue(q, 21);
  //   q = enqueue(q, 25);
  //   q = dequeue(q);
  //       q = enqueue(q, 30);
  //   q = enqueue(q, 31);
  // //  q = enqueue(q, 32);
  //   q = displayQueue(q);
}