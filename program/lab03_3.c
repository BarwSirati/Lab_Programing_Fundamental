#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("* ");
        }
        for (int k = 0; k < (2*(x-i))-1; k++)
        {
            printf("  ");
        }
        for (int l = 0; l < i; l++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < (x * 2) - 1; i++)
    {
        printf("* ");
    }
    printf("\n");
    int dot = x-1;
    for(int i = 0; i<x-1;i++){
        for (int j = 0; j < dot; j++)
        {
            printf("* ");
        }
        for (int k = 0;k<2*i+1;k++){
            printf("  ");
        }
        for (int j = 0; j < dot; j++)
        {
            printf("* ");
        }
        dot--;
        printf("\n");
    }

    return 0;
}
