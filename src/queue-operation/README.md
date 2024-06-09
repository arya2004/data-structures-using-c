# Linked List Queue Operations

This is a simple implementation of a linked list queue in C.

## Usage

1. Include the "queue_operations.h" header file in your C program.
2. Use the functions provided in "queue_operations.c" to perform linked list queue operations.

### Functionality

- `LinkedListQueue newLinkedListQueue(LinkedListQueue linkedlistqueue, int data)`: Creates a new linked list queue with initial data.
- `int sizeLinkedListQueue(LinkedListQueue linkedlistqueue)`: Gets the size of the linked list queue.
- `int rearLinkedListQueue(LinkedListQueue linkedlistqueue)`: Gets the data at the rear of the linked list queue.
- `int frontLinkedListQueue(LinkedListQueue linkedlistqueue)`: Gets the data at the front of the linked list queue.
- `LinkedListQueue enqueueLinkedListQueue(LinkedListQueue linkedlistqueue, int data)`: Enqueues an element into the linked list queue.
- `LinkedListQueue dequeueLinkedListQueue(LinkedListQueue linkedlistqueue)`: Dequeues an element from the linked list queue.
- `LinkedListQueue dropLinkedListQueue(LinkedListQueue linkedlistqueue)`: Drops the linked list queue and frees memory.
- `void displayLinkedListQueue(LinkedListQueue linkedlistqueue)`: Displays the linked list queue.

### Example

```c
#include <stdio.h>
#include "queue_operations.h"

int main() {
    LinkedListQueue queue;
    queue = newLinkedListQueue(queue, 10);
    queue = enqueueLinkedListQueue(queue, 20);
    queue = enqueueLinkedListQueue(queue, 30);
    queue = dequeueLinkedListQueue(queue);
    displayLinkedListQueue(queue);
    return 0;
}
