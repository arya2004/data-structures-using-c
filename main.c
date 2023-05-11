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
  dll = insertEndDoubleLinkedList(dll, 65);
  dll = insertAnyDoubleLinkedList(dll, 109, 3);
  dll = insertAnyDoubleLinkedList(dll, 404, 2);

  displayDoubleLinkekdList(dll);

  dll = deleteBeginningDoubleLinkedList(dll);
  dll = insertBeginningDoubleLinkedList(dll, 92);

  displayDoubleLinkekdList(dll);
  
  dll = deleteAnyDoubleLinkedList(dll ,3);

  displayDoubleLinkekdList(dll);
  printf("\n%i", sizeDoubleLinkedList(dll) );
  printf("\n%i", headDoubleLinkedList(dll) );
  printf("\n%i", tailDoubleLinkedList(dll) );
  dll = dropLinkedList(dll);
    printf("\n%i", sizeDoubleLinkedList(dll) );

}