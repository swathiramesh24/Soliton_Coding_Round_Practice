#include <stdio.h>
#include<string.h>

int allEqual(int freq[], int size)
{
    int val=0;
    for(int i=0;i<size;i++)
    {
        if(freq[i]>0)
        {
            if(val==0)
            {
                val=freq[i];
            }
            else if(freq[i]!=val)
            {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
	char input[100];
	scanf("%s", input);
	
	int n = strlen(input);
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	    arr[i] = input[i]-'0';
	}
	
	int maxLen=0;
	for(int i=0;i<n;i++)
	{
	    int freq[1000]={0};
	    
	    for(int j=i;j<n;j++)
	    {
	        int val = arr[j];
	        freq[val]++;
	        
	        if(allEqual(freq,1000))
	        {
	            int len = j-i+1;
	            if(len>maxLen)
	            {
	                maxLen=len;
	            }
	        }
	    }
	}
	printf("%d",maxLen);
	return 0;
}

