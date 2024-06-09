#include "sorting_utilities.h"

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementation of Bubble Sort algorithm
int* bubbleSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] < array[j]) {
                swap((array + i), (array + j));
            }
        }
    }
    return array;
}

// Implementation of Selection Sort algorithm
int* selectionSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap((array + min), (array + i));
    }
    return array;
}

// Implementation of Insertion Sort algorithm
int* insertionSort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            swap((array + j), (array + j - 1));
            j--;
        }
    }
    return array;
}
