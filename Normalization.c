#include <stdio.h>

void findNormalized(int arr[], int max, int min, int n)
{
    float res[n];
    if(max-min==0)
    {
        for(int i=0;i<n;i++)
        {
            res[i]=0.0;
        }
        
        for(int i=0;i<n;i++)
        {
            printf("%.2f ", res[i]);
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        res[i] = (arr[i]-min)/(float)(max-min);
    }
    for(int i=0;i<n;i++)
    {
        printf("%.2f ", res[i]);
    }
    return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    scanf("%d", &arr[i]);
	}
	
	int min=arr[0],max=arr[0];
	for(int i=0;i<n;i++)
	{
	    if(arr[i]<min)
	    {
	        min=arr[i];
	    }
	    if(arr[i]>max)
	    {
	        max=arr[i];
	    }
	}
	
	findNormalized(arr,max,min,n);
}

