#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct{
    int front;
    int rear;
    int max_size;
    int current_size;
    int *element;
}CircularQueue;

CircularQueue initQueue(CircularQueue queue, int size)
{
    queue.element = (int *) malloc(sizeof(int) * size);
    queue.front = -1;
    queue.rear = -1;
    queue.max_size = size;
    queue.current_size = 0;
    return queue;
}

int isCircularQueueFull(CircularQueue queue)
{
    return queue.current_size == queue.max_size;
}

int isCircularQueueEmpty(CircularQueue queue)
{
    return queue.current_size == 0;
}

int frontCircularQueue(CircularQueue queue)
{
    return queue.element[queue.front];
}

int rearCircularQueue(CircularQueue queue)
{
    return queue.element[queue.rear];
}

CircularQueue enqueueCircularQueue(CircularQueue queue, int element)
{
    if (isCircularQueueFull(queue))
    {
        printf("\nqueue full" );
        exit(3);
    }
    else if (isCircularQueueEmpty(queue))
    {   
        queue.front = 0;
        //queue.rear = (queue.rear + 1)% queue.max_size;
        queue.rear = 0;
        queue.element[queue.rear] = element;
        //queue.current_size = queue.current_size + 1;
        queue.current_size = 1;
    }
    
    else{
        queue.rear = (queue.rear + 1)% queue.max_size;
        queue.element[queue.rear] = element;
        queue.current_size = queue.current_size + 1;
    }
    return queue;
}

CircularQueue dequeueCircularQueue(CircularQueue queue)
{
    if (isCircularQueueEmpty(queue))
    {
        printf("\nqueue empty" );
        exit(3);
    }
    else
    {
        queue.current_size = queue.current_size - 1;
        queue.front = (queue.front + 1)% queue.max_size;
    }
    return queue;
}

void displayCircularQueue(CircularQueue queue)
{   int ptr = queue.front;
    printf("\n FRONT->");
    for (int i = 0; i < queue.current_size; i++)
    {
        printf("%i ", queue.element[ptr]);
        ptr = (ptr + 1) % queue.max_size;
    }
    printf("<-REAR");
}
