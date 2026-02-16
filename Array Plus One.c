#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    scanf("%d", &arr[i]);
	}
	
	int carry=1;
	int j=0;
	int res[n+1];
	
	for(int i=n-1;i>=0;i--)
	{
	    int sum = arr[i]+carry;
	    res[j++]=sum%10;
	    carry=sum/10;
	}
	
	if(carry)
	{
	    printf("%d", carry);
	}
    
    for(int i=j-1;i>=0;i--)
    {
        printf("%d ", res[i]);
    }
}

