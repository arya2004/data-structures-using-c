# Linked List Queue Implementation

This program implements a queue using a linked list data structure. It includes functions for creating a new queue, enqueueing elements, dequeueing elements, dropping the queue, getting the size of the queue, and displaying the queue.

## File Structure

- `linked_list_queue.c`: Contains the main implementation of the linked list queue.
- `linked_list_queue.h`: Header file containing function prototypes and structure definitions.
- `main.c`: Example usage of the linked list queue functions.

## Function Descriptions

- `newLinkedListQueue(int data)`: Creates a new queue with an initial element.
- `sizeLinkedListQueue(LinkedListQueue queue)`: Returns the size of the queue.
- `rearLinkedListQueue(LinkedListQueue queue)`: Returns the element at the rear of the queue.
- `frontLinkedListQueue(LinkedListQueue queue)`: Returns the element at the front of the queue.
- `enqueueLinkedListQueue(LinkedListQueue queue, int data, int priority)`: Enqueues a new element with a priority.
- `dequeueLinkedListQueue(LinkedListQueue queue)`: Dequeues the element at the front of the queue.
- `dropLinkedListQueue(LinkedListQueue queue)`: Drops the entire queue and frees memory.
- `displayLinkedListQueue(LinkedListQueue queue)`: Displays the elements in the queue.

## Usage

1. Include `linked_list_queue.h` in your main file.
2. Use the provided functions to interact with the linked list queue.

## Example

```c
#include <stdio.h>
#include "linked_list_queue.h"

int main() {
    LinkedListQueue queue = newLinkedListQueue(10);
    queue = enqueueLinkedListQueue(queue, 20, 1);
    queue = enqueueLinkedListQueue(queue, 30, 2);
    displayLinkedListQueue(queue);
    queue = dequeueLinkedListQueue(queue);
    displayLinkedListQueue(queue);
    queue = dropLinkedListQueue(queue);
    return 0;
}
