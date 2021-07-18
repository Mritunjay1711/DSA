#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *A, int n)
{
    int indexOfMin;
    printf("Running selection sort...\n");
    for(int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for(int j = i + 1; j < n; j++)   // No. of passes
        {
            if(A[j] < A[indexOfMin])      // Getting index of min element
                indexOfMin = j;
        }
        swap(&A[i], &A[indexOfMin]);       // Swapping A[i] with min element
       
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
    int A[] = {8, 7, 6, 5, 4, 2, 1};
    int n = 7;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);
    
    return 0;
}