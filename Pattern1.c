#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j > (n - i))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        if(i != n)
            printf("\n");
    }
    return 0;
}