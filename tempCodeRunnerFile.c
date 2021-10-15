#include<stdio.h>
#include<stdlib.h>


int main()
{
    int arr[100], flag = 1, n, l = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        flag = 1;
        for(int j = 2; j <= i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            arr[l++] = i;
    }
    for(int i = 0; i < l; i++)
    {
        flag = 1;
        for(int j = i + 1; j < l; j++)
        {
            if(arr[i]+arr[j] == n)
            {
                printf("%d %d\n", arr[i], arr[j]);
                flag = 0;
            }
        }
        if(!flag)
            break;
    }
    return 0;
}