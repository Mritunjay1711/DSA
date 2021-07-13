#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", a->ptr[i]);
    }
}

void setVal(struct myArray *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &a->ptr[i]);
    }
}

int insert(struct myArray *a, int element, int index)
{
    if(a->used_size >= a->total_size)
    {
        return -1;
    }
    for(int i = a->used_size; i >= index; i--)
    {
        a->ptr[i + 1] = a->ptr[i];
    }
    a->ptr[index] = element;
    a->used_size += 1;
}

int main()
{
    struct myArray marks;
    int success;
    createArray(&marks, 10, 5);
    setVal(&marks);
    success = insert(&marks, 7, 1);
    if(success != -1)
        show(&marks);
    else 
        printf("Insertion Failed!");
    
    return 0;
}