#include <stdio.h>
int main()
{
    int x,i=2;
    printf("Enter number : ");
    scanf("%d",&x);
    printf("Factoring Result : ");
    if (x==1)
    {
        printf("1");
        return 0;
    }
    
    while (x!=1)
    {
        //10
        if (x%i == 0)
        {
            printf("%d",i);
            if (x/i != 1)
            {
                printf(" x ");
            }
            x/=i;
        }else{
            i++;
        }
    }
    return 0;
}

