#include <stdio.h>
int main()
{
    int x, y, max = 1, i = 2;
    printf("Enter first number : ");
    scanf("%d", &x);
    printf("Enter second number : ");
    scanf("%d", &y);
    while (i <= x || i <= y)
    {
        if (x % i == 0 && y % i == 0)
        {
            max = i;
        }
        i++;
    }
    printf("Greatest common divisor = %d", max);
    return 0;
}