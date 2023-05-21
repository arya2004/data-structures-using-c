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
//#include "circularlinkedlist.h"
#include "sort.h"
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
{ int pp[10] = {4,6,5,9,1,0,2,8,3,7};
int a = 10;

  int *p = insertionSort(pp, a);
  for (int i = 0; i < 10; i++)
  {
    printf("\n%i", p[i]);
  }
  
  
  return 0;
}