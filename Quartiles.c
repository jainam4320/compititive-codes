#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    void quickSort(int [], int, int);
    int find_mode(int [],int, int);
    int n,i,arr[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0, n-1);
    if(n % 2 == 0)
    {
        if(n/2 % 2 == 0)
        {
            printf("%d\n",find_mode(arr, (n/2), 0));
            printf("%d\n",find_mode(arr, n, 0));
            printf("%d\n",find_mode(arr, (n/2), (n/2)));
        }
        else
        {
            printf("%d\n",arr[((n/2) - 1) / 2]);
            printf("%d\n",find_mode(arr, n, 0));
            printf("%d\n",arr[((n/2) - 1) / 2 + (n/2)]);
        }
    }
    else {
        printf("%d\n",find_mode(arr, ((n+1)/2) - 1, 0));
        printf("%d\n",arr[(n-1)/2]);
        printf("%d\n",find_mode(arr, ((n+1)/2) - 1, ((n+1)/2)));
    }
    return 0;
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
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

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int find_mode(int arr[], int n, int low)
{
    int total;
    if(n % 2 == 0)
    {   
        total = (arr[(n/2) + low] + arr[(n/2) - 1 + low])/2;
    }
    return total;
}