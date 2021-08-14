#include <stdio.h>
int main()
{
    //Original By Barw
    int k = 0,sum;
    for (int i = 1; i <= 10000; i++)
    {
        sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("%d ",sum);
            k++;
        }
    }
    return 0;
}