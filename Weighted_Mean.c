#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int i,n,arr[50][2];
    float total = 0,sum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i][0]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i][1]);
        total = total + (arr[i][0] * arr[i][1]);
        sum = sum + arr[i][1];
    }
    printf("%.1f",total/sum);
    return 0;
}