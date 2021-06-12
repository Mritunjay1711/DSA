#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void scan(struct myArray *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &a->ptr[i]);
    }
}

void print(struct myArray *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("%d ", a->ptr[i]);
    }
    printf("\n");
}

void delete(struct myArray *a, int index)
{
    for(int i = index; i < a->used_size - 1; i++)
    {
        a->ptr[i] = a->ptr[i + 1];
    }
    a->used_size -= 1;
}

int main()
{
    struct myArray arr;
    createArray(&arr, 10, 5);
    scan(&arr);
    print(&arr);
    delete(&arr, 2);
    print(&arr);
    return 0;
}