#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct {
    int front;
    int rear;
    int max_size;
    int current_size;
    int *element;
} CircularQueue;

CircularQueue initQueue(CircularQueue queue, int size);
int isCircularQueueFull(CircularQueue queue);
int isCircularQueueEmpty(CircularQueue queue);
int frontCircularQueue(CircularQueue queue);
int rearCircularQueue(CircularQueue queue);
CircularQueue enqueueCircularQueue(CircularQueue queue, int element);
CircularQueue dequeueCircularQueue(CircularQueue queue);
void displayCircularQueue(CircularQueue queue);

#endif
