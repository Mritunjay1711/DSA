#include<stdio.h>
#include<stdlib.h>

void insetionSort(int *A, int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1, key = A[i];
        while(A[j] > key && j >= 0)
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
    int A[] = {8, 6, 7, 5, 4, 3, 2, 1};
    int n = 8;
    printArray(A, n);
    insetionSort(A, n);
    printArray(A,n);
    return 0;
}