#include "search_utilities.h"

// Implementation of linear search
int linearSearch(int *array, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (*(array + i) == num) {
            return i;
        }
    }
    return -1;
}
