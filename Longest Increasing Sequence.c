#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int left=0;
    while(left<n-1 && arr[left]<arr[left+1])
    {
        left++;
    }
    
    if(left == n-1)
    {
        printf("Sorted");
        return 0;
    }
    
    int right = n-1;
    while(right>=0 && arr[right]>=arr[right-1])
    {
        right--;
    }
    
    int bestL=0,bestR=right-1;
    int minRemove = right;
    
    if(n-left-1<minRemove)
    {
        minRemove = n-left-1;
        bestL = left+1;
        bestR = n-1;
    }
    
    int i=0, j=right;
    while(i<=left && j<n)
    {
        if(arr[i]<=arr[j])
        {
            if(j-i-1<minRemove)
            {
                minRemove = j-i-1;
                bestL = left+1;
                bestR = j-1;
            }
            i++;
        }
            else
            {
                j++;
            }
    }
    
    printf("%d\n", minRemove);
    printf("%d %d\n", bestL+1, bestR+1);
}

