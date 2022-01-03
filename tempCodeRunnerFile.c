#include<stdio.h>
#include<stdlib.h>


int main()
{
    char c[] = "KIITUNIVERSITY";
    char *p = c;
    printf("%s\n", p + p[3] - p[1]);
    return 0;
}