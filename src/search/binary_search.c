#include "search_utilities.h"

// Recursive implementation of binary search
int binarySearch(int *sortedArray, int size, int low, int high, int mid, int num) {
    if (*(sortedArray + mid) == num) {
        return mid;
    } else if (*(sortedArray + mid) > num) {
        return binarySearch(sortedArray, size, low, mid, (mid + low) / 2, num);
    } else if (*(sortedArray + mid) < num) {
        return binarySearch(sortedArray, size, mid, high, (mid + high) / 2, num);
    }
}
