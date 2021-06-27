#include<stdio.h>

void sort(int arr[], int size)
{
    
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int binarySearch(int arr[], int size, int element)   //(Time complexity O(log n with base 2))
{
    int mid, low, high;
    low = 0;
    high = size - 1;

    //Keeps searching until low <= high
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] == element)
        {
            return mid;
        }
        if(element > arr[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    //Searching end
    return -1;
}

int main()
{
    int arr[] = {2,6,3,6,8,4,2,1};
    int n;
    printf("Enter the number to search: ");
    scanf("%d", &n);
    int size = sizeof(arr)/sizeof(int);
    sort(arr, size);
    int index = binarySearch(arr, size, n);
    printf("The element %d was found at index %d.\n", n, index);
    return 0;
}