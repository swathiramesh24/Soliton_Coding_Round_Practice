#include <stdio.h>
#include<limits.h>

int main() {
	
	int n;
	scanf("%d", &n);
	int max = INT_MIN;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	   scanf("%d", &arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
	    if(arr[i]>max)
	    {
	        max=arr[i];
	    }
	}
	
	printf("Maximum number : %d", max);
	return 0;

}

