#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

typedef struct{
    int front;
    int rear;
    int size;
    int *element;
    int currentSize;
}Queue;

Queue initQueue(Queue queue, int size){
    queue.element = (int *) malloc(sizeof(int) * size);
    queue.front = -1;
    queue.rear = -1;
    queue.size = size;
    queue.currentSize = 0;
    return queue;
}

Queue enqueue(Queue queue, int element){
    if(queue.front == -1 && queue.rear == -1){
        queue.front = 0;
        queue.rear = 0;
        queue.element[queue.rear] = element;
        queue.currentSize = 1;
    }
    else if (queue.rear < queue.size - 1)
    {
        queue.rear = queue.rear + 1;
        queue.element[queue.rear] = element;
        queue.currentSize +=1;
    }
    else if(queue.rear == queue.size -1){
       printf("\nqueue full" );
      
       exit(3);
    }
    return queue;
    
    
}

Queue dequeue(Queue queue){

    Queue temp  = initQueue(temp, queue.size);
    for (int i = queue.front + 1; i <= queue.rear; i++)
    {
        temp = enqueue(temp, queue.element[i]);
    }
    free(queue.element);
    
    return temp;
}

Queue displayQueue(Queue queue){
    printf("\n");
    for (int i = 0; i <= queue.rear; i++)
    {
        printf("%i ", queue.element[i]);
    }
    return queue;
}


