# Queue Operations

This is a simple implementation of a queue in C.

## Usage

1. Include the "queue_operations.h" header file in your C program.
2. Use the functions provided in "queue_operations.c" to perform queue operations.

### Functionality

- `Queue initQueue(int size)`: Initializes a queue of the specified size.
- `Queue enqueue(Queue queue, int element)`: Adds an element to the queue.
- `Queue dequeue(Queue queue)`: Removes an element from the queue.
- `Queue displayQueue(Queue queue)`: Displays the elements in the queue.

### Example

```c
#include <stdio.h>
#include "queue_operations.h"

int main() {
    Queue queue = initQueue(5);
    queue = enqueue(queue, 10);
    queue = enqueue(queue, 20);
    queue = enqueue(queue, 30);
    queue = dequeue(queue);
    queue = displayQueue(queue);
    return 0;
}
