#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int partition(int *A, int lb, int ub)
{
    int i = lb, j = ub;
    int ind = (lb + ub)/2;
    int pivot = A[ind];
    while (i < j)
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
    
    swap(&A[j], &A[ind]);
    printf("%d ", j);
    return j;
}
void quicksort(int *A, int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
        if(p != 0)
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, h);
    }
}
void printArray(int *A, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {4, 23, 99, 1, 43, 9};
    int n = 6;
    printArray(A, n);
    quicksort(A, 0, 5);
    printArray(A, n);
    return 0;
}