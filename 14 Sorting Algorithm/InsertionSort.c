#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for each pass
    for(int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        // Loop for each pass
        while(j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
       
    }
}

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {7, 1, 2, 11, 8};
    int n = 5;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);     
    return 0;
}