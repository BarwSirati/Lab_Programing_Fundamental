#include <stdio.h>
#include <string.h>
char x[1000100];
char y[1000100];
int main()
{
    int sum = 0;
    scanf("%s", x);
    for (int i = 0; i < strlen(x); i++)
    {
        sum += x[i] - '0';
    }
    sprintf(y, "%d", sum);
    while (strlen(y) != 1)
    {
        sum = 0;
        for (int i = 0; i < strlen(y); i++)
        {
            sum+=y[i] - '0';
        }
        sprintf(y, "%d", sum);
    }
    printf("%s",y);
    return 0;
}