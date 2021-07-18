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
    
    do
    {
        while(A[i] <= pivot)
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

    swap(&A[low], &A[j]);

    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex; // Store the index of partition

    if(low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1); //Sort left subarray
        quickSort(A, partitionIndex + 1, high); // Sort right subarray
    }
}

int main()
{
    /*
       DRY RUN

       22, 2, 6, 132, 43, 42, 1, 3  First pass

                            i               j           
     -->(pivot)  22,| 2, 6, 132, 43, 42, 1, 3  (swap A[i] & A[j] since i < j)
                               i       j
                 22,| 2, 6, 3, 43, 42, 1, 132   (swap A[i] & A[j] since i < j)
                               j  i   
                 22,| 2, 6, 3, 1, 42, 43, 132   (i > j so swap A[pivot] with A[j])  

                 1, 2, 6, 3, |22|, 42, 43, 132    (j = 4 therefore partitionIndex = 4 and returns 4)
                               
    */
    int A[] = {22, 2, 6, 132, 43, 42, 1, 3};
    int n = 8;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    
    return 0;
}