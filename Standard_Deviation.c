#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int i,n;
    double mean,total = 0,arr[100];
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&arr[i]);
        mean += arr[i];
    }
    mean /= n;
    for(i=0;i<n;i++)
    {
        arr[i] -= mean;
        arr[i] *= arr[i];
        total += arr[i];
    }
    total /= n;
    printf("%.1lf",sqrtf(total));
    return 0;
}
