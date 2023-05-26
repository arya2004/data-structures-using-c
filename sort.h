#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 

}


int* bubbleSort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(array[i] < array[j])
            {
                swap((array + i), (array + j));
            }
        }
        
    }
    return array;
}

// int * selectionSort1(int* array, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             if(array[i] > array[j])
//             {
//                 swap((array + i), (array + j));
//             }
//         }
        
//     }
//     return array;
// }

int * selectionSort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {   int min = i;
        for (int j = i; j < size; j++)
        {
            if (array[j] < array[min] )
            {
                min = j;
            }
            
        }
        swap((array + min), (array + i));
        
    }
    return array;
}

int * insertionSort(int * array, int size)
{   
    for (int i = 1; i < size; i++) 
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j]) 
        {
            swap((array + j), (array + j -1));
            j--;
        }
    }
    
    
    
    return array;
}