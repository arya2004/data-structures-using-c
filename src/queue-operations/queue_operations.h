#ifndef QUEUE_OPERATIONS_H
#define QUEUE_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int *element;
    int currentSize;
} Queue;

// Function prototypes
Queue initQueue(int size);
Queue enqueue(Queue queue, int element);
Queue dequeue(Queue queue);
Queue displayQueue(Queue queue);

#endif /* QUEUE_OPERATIONS_H */
