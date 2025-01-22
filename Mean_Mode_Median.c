#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    void quickSort(int [], int, int);
    int n,i,j,temp,select[2500],arr[2500];
    float total = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        total += arr[i];
    }
    printf("%.1f\n",total/n);
    quickSort(arr, 0, n-1);
    if(n % 2 == 0)
    {   
        total = (float)(arr[n/2] + arr[(n/2) - 1])/2;
        printf("%.1f\n",total);
    }
    else {
        printf("%d\n",arr[(n-1)/2]);
    }
    for(i=0;i<n;i++)
    {
        temp = arr[i];
        select[i] = 1;
        for(j=0;j<n;j++)
        {
            if(i != j)
            {
                if(temp == arr[j])
                {
                    select[i]++;
                }
            }
        }
    }
    temp = 0;
    for(i=1;i<n;i++)
    {
        if(select[i] > select[temp])
        {
            temp = i;
        }
    }
    printf("%d",arr[temp]);
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