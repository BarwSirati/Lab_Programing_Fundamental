#include <stdio.h>
int temp;
int gcd(int max, int min)
{
    if (max % min != 0)
    {
        temp = min;
        min = max%min; 
        max = temp;
        return gcd(max,min);
    }else{
        return min;
    }
}
int main()
{
    //Original By Barw
    int x[2], max = 1, i = 2;
    printf("Enter first number : ");
    scanf("%d", &x[0]);
    printf("Enter second number : ");
    scanf("%d", &x[1]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 2; j++)
        {
            if (x[i] > x[j])
            {
                int temp = x[j];
                x[j] = x[i];
                x[i] = temp;
            }
        }
    }
    printf("%d", gcd(x[1], x[0]));
    return 0;
}