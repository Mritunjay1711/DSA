#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
        else
            return -1;
    }
}
int main()
{
    int arr[] = {2, 4, 6, 9, 1, 10};
    int n, index;
    printf("Enter the element to search: ");
    scanf("%d", &n);
    index = linearSearch(arr, 6, n);
    printf("The element %d was found at index %d\n", n, index);
    return 0;
}