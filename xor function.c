#include <stdio.h>
#include<string.h>
#include<limits.h>

int xorFunction(int a, int b)
{
    return a^b;
}

int main() {
	int vxor=INT_MAX;
	int n=0,i1=0,i2=0;
	int arr[100];
	
	while(scanf("%d", &arr[n])==1)
	{
	    n++;
	    char ch = getchar();
	    if(ch=='\n' || ch==EOF)
	    {
	        break;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    for(int j=i+1;j<n;j++)
	    {
	        int x = xorFunction(arr[i], arr[j]);
	        if(x<vxor)
	        {
	            vxor=x;
	            i1=arr[i];
	            i2=arr[j];
	        }
	    }
	}
	printf("%d\n", vxor);
	printf("%d %d", i1,i2);
	return 0;
}

