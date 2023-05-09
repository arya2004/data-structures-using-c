#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
typedef struct{
    int top;
    int size;
    int *element;
}Stack;

Stack initStack(Stack stack,int size){
    stack.size = size;
    stack.top = -1;
    stack.element = (int *)malloc(sizeof(int)* size);
    return stack;
}

int isFull(Stack stack){
    if (stack.top == stack.size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Stack stack){
    if (stack.top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int peek(Stack stack){
    return stack.element[stack.top];
    
}

Stack push(Stack stack, int x){
    if (!isFull(stack))
    {
        stack.top = stack.top + 1;
        stack.element[stack.top] = x;
    }
    else{
        printf("\nstack full");
        exit(1);
    }
    return stack;
}

Stack pop(Stack stack){
    if (!isEmpty(stack))
    {
        stack.top = stack.top -1;

    }
    else{
        printf("\nstack empty");
        exit(1);
    }
    return stack;
    
}

Stack displayStack(Stack stack){
    printf("\n");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%i ", stack.element[i]);
    }
    return stack;
}