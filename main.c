#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
//#include "stack_array.h"
#include "doublelinkedlist.h"
//#include "queue_array.h"
//#include "linkedlist.h"
//#include "stack_linkedlist.h"
//#include "queue_linkedlist.h"
//#include "circularqueue_array.h"
//#include "merge_sort.h"
//#include "search.h"
//#include "circularlinkedlist.h"
//#include "sort.h"
//#include"inf_post.h"

DoubleLinkedList reverseLinkedList(DoubleLinkedList doublelinkedlist){
    Node* temp = doublelinkedlist.head;
    Node* swap = NULL;
    while (temp != NULL)
    {  
        swap = temp->next;
        temp->next = temp->previous;
        temp->previous = swap;
        temp = temp->previous;  
       
    }
    
    return doublelinkedlist;
}

int main()
{
   DoubleLinkedList dll = newDoubleLinkedList(dll, 34);
   dll = insertEndDoubleLinkedList(dll, 11);
   dll = insertEndDoubleLinkedList(dll, 54);
   dll = insertEndDoubleLinkedList(dll, 192);
   dll = insertEndDoubleLinkedList(dll, 304);
   displayDoubleLinkekdList(dll);
   dll = reverseLinkedList(dll);
   displayDoubleLinkekdList(dll);
   
}