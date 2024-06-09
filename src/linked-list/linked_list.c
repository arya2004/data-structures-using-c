// linked_list.c - Implementation of linked list operations
#include "linked_list.h"
#include<stdio.h>
#include<stdlib.h>

// Function to create a new linked list with one node
LinkedList newLinkedList(int data) {
    LinkedList linkedlist;
    linkedlist.head = (Node*)malloc(sizeof(Node));
    linkedlist.tail = linkedlist.head;
    linkedlist.size = 1;
    linkedlist.head->link = NULL;
    linkedlist.head->data = data;
    return linkedlist;
}

// Function to get the size of the linked list
int sizeLinkedList(LinkedList linkedlist) {
    return linkedlist.size;
}

// Function to get the data in the tail node of the linked list
int tailLinkedList(LinkedList linkedlist) {
    return linkedlist.tail->data;
}

// Function to get the data in the head node of the linked list
int headLinkedList(LinkedList linkedlist) {
    return linkedlist.head->data;
}

// Function to insert a new node at the end of the linked list
LinkedList insertEndLinkedList(LinkedList linkedlist, int data) {
    linkedlist.tail->link = (Node*)malloc(sizeof(Node));
    linkedlist.tail->link->data = data;
    linkedlist.tail->link->link = NULL;
    linkedlist.tail = linkedlist.tail->link;
    linkedlist.size++;
    return linkedlist;
}

// Function to insert a new node at the beginning of the linked list
LinkedList insertBeginningLinkedList(LinkedList linkedlist, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = linkedlist.head;
    linkedlist.head = temp;
    linkedlist.size++;
    return linkedlist;
}

// Function to insert a new node at any position in the linked list
LinkedList insertAnyLinkedList(LinkedList linkedlist, int data, int position) {
    if (position < 1 || position > linkedlist.size + 1) {
        printf("\nPosition out of bounds in insertAnyLinkedList");
        exit(1);
    } else if (position == 1) {
        linkedlist = insertBeginningLinkedList(linkedlist, data);
    } else if (position == linkedlist.size + 1) {
        linkedlist = insertEndLinkedList(linkedlist, data);
    } else {
        Node* temp = (Node*)malloc(sizeof(Node));
        Node* ptr = linkedlist.head;
        for (int i = 1; i < position - 1; i++) {
            ptr = ptr->link;
        }
        temp->data = data;
        temp->link = ptr->link;
        ptr->link = temp;
        linkedlist.size++;
    }
    return linkedlist;
}

// Function to delete the first node of the linked list
LinkedList deleteBeginningLinkedList(LinkedList linkedlist) {
    if (linkedlist.size == 0) {
        printf("\nLinked list is empty in deleteBeginningLinkedList");
        exit(1);
    } else if (linkedlist.size == 1) {
        linkedlist = dropLinkedList(linkedlist);
    } else {
        Node* temp = linkedlist.head;
        linkedlist.head = linkedlist.head->link;
        free(temp);
        linkedlist.size--;
    }
    return linkedlist;
}

// Function to delete the last node of the linked list
LinkedList deleteEndLinkedList(LinkedList linkedlist) {
    if (linkedlist.size == 0) {
        printf("\nLinked list is empty in deleteEndLinkedList");
        exit(1);
    } else if (linkedlist.size == 1) {
        linkedlist = dropLinkedList(linkedlist);
    } else {
        Node* temp = linkedlist.head;
        for (int i = 1; i < linkedlist.size - 1; i++) {
            temp = temp->link;
        }
        linkedlist.tail = temp;
        free(temp->link);
        temp->link = NULL;
        linkedlist.size--;
    }
    return linkedlist;
}

// Function to delete a node at any position in the linked list
LinkedList deleteAnyLinkedList(LinkedList linkedlist, int position) {
    if (linkedlist.size == 0) {
        printf("\nLinked list is empty in deleteAnyLinkedList");
        exit(1);
    } else if (position < 1 || position > linkedlist.size) {
        printf("\nPosition out of bounds in deleteAnyLinkedList");
        exit(1);
    } else if (linkedlist.size == 1) {
        linkedlist = dropLinkedList(linkedlist);
    } else if (position == 1) {
        linkedlist = deleteBeginningLinkedList(linkedlist);
    } else if (position == linkedlist.size) {
        linkedlist = deleteEndLinkedList(linkedlist);
    } else {
        Node* current = linkedlist.head;
        Node* previous = linkedlist.head;
        for (int i = 1; i < position - 1; i++) {
            previous = previous->link;
        }
        current = previous->link;
        previous->link = current->link;
        free(current);
        linkedlist.size--;
    }
    return linkedlist;
}

// Function to drop (delete) the entire linked list
LinkedList dropLinkedList(LinkedList linkedlist) {
    Node* temp = linkedlist.head;
    while (temp != NULL) {
        temp = temp->link;
        free(linkedlist.head);
        linkedlist.head = temp;
    }
    linkedlist.size = 0;
    return linkedlist;
}

// Function to display the linked list
void displayLinkedList(LinkedList linkedlist) {
    printf("\nHEAD");
    Node* temp = linkedlist.head;
    while (temp != NULL) {
        printf("->%i", temp->data);
        temp = temp->link;
    }
    printf("<-TAIL");
}
