#include <stdio.h>

void reverse(int arr[], int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int n, int d)
{
    if(n<=1) return;
    
    d=d%n;
    
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int d;
    scanf("%d", &d);
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    rotate(arr, n, d);
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}
