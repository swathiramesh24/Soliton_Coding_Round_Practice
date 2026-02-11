#include <stdio.h>
int firstRepeatingElement(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int num = firstRepeatingElement(arr,n);
    printf("%d", num);
}

