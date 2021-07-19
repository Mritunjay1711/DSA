#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do{
        while(A[i] < pivot)
        {
            i++;
        }

        while(A[j] > pivot)
        {
            j--;
        }
        if(i < j)
            swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[j], &A[low]);
    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex;   // Index of partitioned element
    if(low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // Left subarray
        quickSort(A, partitionIndex + 1, high); // Right subarray
    }
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int low = 0;
    int high = 9;
    int n = 10;

    printArray(A, n);
    quickSort(A, low, high);
    printArray(A, n);
    
    return 0;
}