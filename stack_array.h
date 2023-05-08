#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct{
    int count;
    int size;
    int *element;
}Stack;

Stack init(Stack stack,int size){
    stack.size = size;
    stack.count = -1;
    stack.element = (int *)malloc(sizeof(int)* size);
    return stack;
}