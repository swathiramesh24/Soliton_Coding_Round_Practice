#include <stdio.h>
#include<limits.h>

void reverse(int arr[], int n)
{
    int l=0, r=n-1;
    
    while(l<r)
    {
        int temp = arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        
        l++;
        r--;
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    reverse(arr, n);
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}
