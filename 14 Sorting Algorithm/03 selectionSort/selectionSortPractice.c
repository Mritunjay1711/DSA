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
    for(int i = 0; i < n - 1; i++)
    {
        int indexOfMin = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[indexOfMin] > A[j])
                indexOfMin = j;
        }
        swap(&A[indexOfMin], &A[i]);
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
    int A[] = {89, 23, 98, 34, 21};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);   
    return 0;
}