#include <stdio.h>

int findMajorityElement(int arr[], int n)
{
    int num=0,count=0;
    for(int i=0;i<n;i++)
    {
        if(count==0)
        {
            num=arr[i];
        }
        
        if(num==arr[i]) count++;
        else count--;
    }
    return num;
}


int main() {
    int n=0;
	int arr[100];
	
	while(scanf("%d", &arr[n])==1)
	{
	    n++;
	    char ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
	}
	
	int res = findMajorityElement(arr,n);
	printf("%d", res);
}

