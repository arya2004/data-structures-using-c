#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
//#include "stack_array.h"
//#include "linkedlist.h"
//#include "queue_array.h"
#include "doublelinkedlist.h"
//#include "stack_linkedlist.h"
//#include "queue_linkedlist.h"


int main()
{   
   DoubleLinkedList dll = newDoubleLinkedList(dll, 34);//initialize
  dll = insertBeginningDoubleLinkedList(dll, 99);
  
displayDoubleLinkekdList(dll);
dll = deleteBeginningDoubleLinkedList(dll);dll = deleteBeginningDoubleLinkedList(dll);dll = deleteBeginningDoubleLinkedList(dll);
displayDoubleLinkekdList(dll);

}