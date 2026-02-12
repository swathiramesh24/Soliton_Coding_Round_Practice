#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int arr[100];
	for(int i=0;i<n;i++)
	{
	    scanf("%d", &arr[i]);
	}
	
	int c = 1;
	for(int i=n-1;i>=0;i--)
	{
	    int sum = arr[i]+c;
	    arr[i] = sum%10;
	    c=sum/10;
	}
    
    if(c)
    {
        printf("%d ", c);
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

