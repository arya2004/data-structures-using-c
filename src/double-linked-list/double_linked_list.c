#include "double_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList newDoubleLinkedList(int data) {
    DoubleLinkedList doublelinkedlist;
    doublelinkedlist.size = 1;
    doublelinkedlist.head = (Node*)malloc(sizeof(Node));
    doublelinkedlist.head->data = data;
    doublelinkedlist.head->previous = NULL;
    doublelinkedlist.head->next = NULL;
    doublelinkedlist.tail = doublelinkedlist.head;
    return doublelinkedlist;
}

int sizeDoubleLinkedList(DoubleLinkedList doublelinkedlist) {
    return doublelinkedlist.size;
}

int headDoubleLinkedList(DoubleLinkedList doublelinkedlist) {
    return doublelinkedlist.head->data;
}

int tailDoubleLinkedList(DoubleLinkedList doublelinkedlist) {
    return doublelinkedlist.tail->data;
}

DoubleLinkedList insertEndDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data) {
    doublelinkedlist.tail->next = (Node*)malloc(sizeof(Node));
    doublelinkedlist.tail->next->data = data;
    doublelinkedlist.tail->next->previous = doublelinkedlist.tail;
    doublelinkedlist.tail->next->next = NULL;
    doublelinkedlist.size++;
    doublelinkedlist.tail = doublelinkedlist.tail->next;
    return doublelinkedlist;
}

DoubleLinkedList insertBeginningDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data) {
    doublelinkedlist.head->previous = (Node*)malloc(sizeof(Node));
    doublelinkedlist.size++;
    doublelinkedlist.head->previous->data = data;
    doublelinkedlist.head->previous->next = doublelinkedlist.head;
    doublelinkedlist.head->previous->previous = NULL;
    doublelinkedlist.head = doublelinkedlist.head->previous;
    return doublelinkedlist;
}

DoubleLinkedList insertAnyDoubleLinkedList(DoubleLinkedList doublelinkedlist, int data, int position) {
    if (position < 1 || position > doublelinkedlist.size + 1) {
        printf("\nPosition out of bounds in insertAnyDoubleLinkedList");
        exit(1);
    } else if (position == 1) {
        doublelinkedlist = insertBeginningDoubleLinkedList(doublelinkedlist, data);
    } else if (position == doublelinkedlist.size + 1) {
        doublelinkedlist = insertEndDoubleLinkedList(doublelinkedlist, data);
    } else {
        Node* temp = (Node*)malloc(sizeof(Node));
        Node* ptr = doublelinkedlist.head;
        for (int i = 1; i < position - 1; i++) {
            ptr = ptr->next;
        }
        temp->data = data;
        temp->next = ptr->next;
        ptr->next = temp;
        temp->previous = ptr;
        temp->next->previous = temp;
        doublelinkedlist.size++;
    }
    return doublelinkedlist;
}

// Implement other functions similarly

