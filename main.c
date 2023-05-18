#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "stack_array.h"
//#include "doublelinkedlist.h"
//#include "queue_array.h"
//#include "linkedlist.h"
//#include "stack_linkedlist.h"
//#include "queue_linkedlist.h"
//#include "circularqueue_array.h"
//#include "merge_sort.h"
//#include "search.h"
#include "circularlinkedlist.h"
// int q ()
// {
//   int a[10] = {11,22,33,44,55,67,77,88,99, 100};
//   int s = 10;
//   int num = 101;
//   int mid = 
//   printf("\n%i", binarySearch(a,10,0,10,(0+9)/2, num));

//   return 0;
// }
int main ()
{
  LinkedList ll = newLinkedList(ll, 77);
 // ll = insertEndLinkedList(ll, 69);
 ll = insertBeginningLinkedList(ll, 99);
   printf("\n%i", ll.head->data);
  printf("\n%i", ll.head->link->data);
  printf("\n%i", ll.head->link->link->data);
   printf("\n%i", ll.head->link->link->link->data);

  return 0;
}