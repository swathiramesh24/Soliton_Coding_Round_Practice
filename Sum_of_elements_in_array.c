#include <stdio.h>
#include<limits.h>

int main() {
	
	int n;
	scanf("%d", &n);
	int sum=0;
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	   scanf("%d", &arr[i]);
	}
	
	for(int i=0;i<n;i++)
	{
	    sum += arr[i];
	}
	
	printf("Sum : %d", sum);
	return 0;

}

