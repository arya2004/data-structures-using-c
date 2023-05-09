#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
#include "stack_array.h"
//#include "queue_array.h"

int main()
{   
    
    Stack stack = initStack(stack, 5);
    stack = push(stack, 7);stack = push(stack, 3);stack = push(stack, 22);stack = push(stack, 10);
    stack = displayStack(stack);
    stack = pop(stack);
     stack = push(stack, 88);
    stack = push(stack, 11);
    // stack = push(stack, 33);
    printf("\n%i", peek(stack));
    stack = displayStack(stack);

    
}