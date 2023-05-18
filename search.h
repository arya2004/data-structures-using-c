#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

int linearSearch(int *array,int size, int num)
{
    for (int i = 0; i < size; i++)
    {
       if (*(array + i) == num)
       {
        return i;
       }
       
    }
    return -1;
    
}

int binarySearch(int *sortedArray, int size,int low, int high, int mid, int num )
{
    if (*(sortedArray + mid) == num)
    {
        return mid;
    }
    else if (*(sortedArray + mid) > num)
    {
        return binarySearch(sortedArray, size, low,  mid, (mid + low)/2, num );
    }
    else if (*(sortedArray + mid) < num)
    {
        return binarySearch(sortedArray,  size, mid,  high, (mid + high)/2, num );
    }
    
}