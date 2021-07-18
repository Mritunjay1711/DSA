#include<stdio.h>

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp, isSorted = 0;
    for(int i = 0; i < n - 1; i++)  // No. of passes
    {
        isSorted = 1;
        printf("Working on pass number %d.\n", i + 1);
        for(int j = 0; j < (n - 1 - i); j++)   // For comparison in each pass
        {
            if(A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}

void bubbleSort(int *A, int n)
{
    int temp;
    for(int i = 0; i < n - 1; i++)  // No. of passes
    {
        printf("Working on pass number %d.\n", i + 1);
        for(int j = 0; j < (n - 1 - i); j++)   // For comparison in each pass
        {
            if(A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}



int main()
{
    // int A[] = {101, 54, 64, 2, 32, 9};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int A[] = {2, 3, 5, 999, 7, 234, 98, 77, 123};
    int B[] = {2, 3, 5, 999, 7, 234, 98, 77, 123};
    int n = 9;
    printArray(A, n);
    printf("Normal Sort: \n");
    bubbleSort(A, n);
    printf("Adaptive Sorting: \n");
    bubbleSortAdaptive(B, n);
    printArray(A, n);
    printArray(B, n);
            
    return 0;
}