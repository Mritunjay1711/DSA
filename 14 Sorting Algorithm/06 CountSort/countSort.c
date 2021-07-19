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

void countSort(int *A, int n)
{
    int j, k;
    // Finding maximum element in A
    int max = A[0];
    for(int i = 0; i < n; i++)
    {
        if(max < A[i])
            max = A[i];
    }
    // Creating count array and initialsing to zero
    int *count = (int*)calloc((max + 1), sizeof(int));

    // Increment the corresponding array in count array
    for(int i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    j = 0; // Counter for count array
    k = 0; // Counter for given array

    while(j < max + 1)
    {
        if(count[j] > 0)
        {
            A[k] = j;
            count[j]--;
            k++; 
        }
        else
        {
            j++;
        }
    }
    

}

int main()
{
    int A[] = {7, 1, 2, 11, 8};
    int n = 5;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n); 
    
    return 0;
}