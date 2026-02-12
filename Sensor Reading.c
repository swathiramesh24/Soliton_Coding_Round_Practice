#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int min,max,count=0,k=0;
    scanf("%d %d", &min, &max);
    int res[100];
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=min && arr[i]<=max)
        {
            count++;
        }
        else
        {
            res[k++]=i;
        }
    }
    
    if(count==n) printf("Safe\n");
    else if(count <= n/2) printf("Warning\n");
    else if(count==0) printf("Critical\n");
    
    for(int i=0;i<k;i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}

