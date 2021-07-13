#include<stdio.h>

int binarySearch(int arr[], int element, int size)
{
    int mid, low, high;

    low = 0;
    high = size - 1;

    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == element)
            return mid;
        
        if(element > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 5, 6, 33, 64, 23, 45};
    int n, size = sizeof(arr)/sizeof(int);
    printf("Enter the element to find in array: ");
    scanf("%d", &n);

    int index = binarySearch(arr, n, size);
    printf("The element %d is at %d index.\n", n, index);
    return 0;
}