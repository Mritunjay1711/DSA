#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1, k = low;
    int B[100];

    while(i <= mid && j <= high)
    {
        if(A[i] < A[j])
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
    while(i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for(int i = 0; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int *A, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
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