#include "queue_operations.h"

// Initialize the queue
Queue initQueue(int size) {
    Queue queue;
    queue.element = (int *)malloc(sizeof(int) * size);
    queue.front = -1;
    queue.rear = -1;
    queue.size = size;
    queue.currentSize = 0;
    return queue;
}

// Add an element to the queue
Queue enqueue(Queue queue, int element) {
    if (queue.front == -1 && queue.rear == -1) {
        queue.front = 0;
        queue.rear = 0;
        queue.element[queue.rear] = element;
        queue.currentSize = 1;
    } else if (queue.rear < queue.size - 1) {
        queue.rear = queue.rear + 1;
        queue.element[queue.rear] = element;
        queue.currentSize += 1;
    } else if (queue.rear == queue.size - 1) {
        printf("\nQueue full");
        exit(3);
    }
    return queue;
}

// Remove an element from the queue
Queue dequeue(Queue queue) {
    Queue temp = initQueue(queue.size);
    for (int i = queue.front + 1; i <= queue.rear; i++) {
        temp = enqueue(temp, queue.element[i]);
    }
    free(queue.element);
    return temp;
}

// Display the elements in the queue
Queue displayQueue(Queue queue) {
    printf("\n");
    for (int i = 0; i <= queue.rear; i++) {
        printf("%i ", queue.element[i]);
    }
    return queue;
}
