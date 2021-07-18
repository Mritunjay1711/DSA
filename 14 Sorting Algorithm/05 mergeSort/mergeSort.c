#include <stdio.h>
#include <stdlib.h>

/*  ***HOW MERGE SORT WORK***
void merge(int A[], int B[], int C[], int m, int n)
{
    int i, j, k;
    i = j = k = 0;

    while(i < m && j < n)
    {
        if(A[i]  < B[j])
        {
            C[k] = A[i];
            k++, i++;
        }
        else
        {
            C[k] = B[j];
            k++, j++;
        }
    }
    while(i < m)
    {
        C[k] = A[i];
        k++, i++;
    }
    while(j < n)
    {
        C[k] = B[j];
        k++, j++;
    }
}

*/

void merge(int *A, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[100];

    
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    
    for (int i = 0; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int *A, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {2, 5, 1, 98, 34};
    int l = 0;
    int h = 4;
    int n = 5;
    printArray(A, 5);
    mergeSort(A, l, h);
    printArray(A, 5);

    return 0;
}