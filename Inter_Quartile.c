#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    void quickSort(long int [], long int, long int);
    double find_mode(long int [], long int, long int);
    int n1,i,arr[100];
    long int n2,j,k,s[100000];
    double q1,q3;
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        scanf("%d",&arr[i]);
    }
    n2 = 0;
    for(i=0;i<n1;i++)
    {
        scanf("%ld",&j);
        for(k=0;k<j;k++)
        {
            s[n2++] = arr[i];
        }
    }
    quickSort(s, 0, n2-1);
    if(n2 % 2 == 0)
    {
        if(n2/2 % 2 == 0)
        {
            q1 = find_mode(s, (n2/2), 0);
            q3 = find_mode(s, (n2/2), (n2/2));
        }
        else
        {
            q1 = (double)s[((n2/2) - 1) / 2];
            q3 = (double)s[((n2/2) - 1) / 2 + (n2/2)];
        }
    }
    else {
        if((n2+1)/2 % 2 == 0)
        {
            q1 = (double)s[((n2+1)/4) - 1];
            q3 = (double)s[((n2+1)/4) - 1 + ((n2+1)/2)];
        }
        else
        {
            q1 = find_mode(s, ((n2+1)/2) - 1, 0);
            q3 = find_mode(s, ((n2+1)/2) - 1, ((n2+1)/2));
        }
    }
    printf("%.1lf",q3-q1);
    return 0;
}
void swap(long int* a, long int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (long int arr[], long int low, long int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(long int arr[], long int low, long int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

double find_mode(long int arr[], long int n, long int low)
{
    double total;
    if(n % 2 == 0)
    {   
        total = (double)(arr[(n/2) + low] + arr[(n/2) - 1 + low])/2;
    }
    return total;
}