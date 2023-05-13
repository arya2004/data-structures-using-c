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
#include "circularqueue_array.h"
int main ()
{
  CircularQueue c = initQueue(c, 4);//max size is 4
  c = enqueueCircularQueue(c, 100);
  c = enqueueCircularQueue(c, 600);
  c = enqueueCircularQueue(c, 303);
  c = enqueueCircularQueue(c, 201);

  displayCircularQueue(c);

  c = dequeueCircularQueue(c);
  c = dequeueCircularQueue(c);
  c = enqueueCircularQueue(c, 40);
  c = enqueueCircularQueue(c, 404);

  displayCircularQueue(c);
  printf("\n%i", frontCircularQueue(c) );
  printf("\n%i", rearCircularQueue(c) );
  printf("\n%i", isCircularQueueFull(c) );
  printf("\n%i", isCircularQueueEmpty(c) );

  return 0;
}