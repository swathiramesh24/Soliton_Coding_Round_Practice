#include <stdio.h>

int main() {
	char name1[50];
	char name2[50];
	int count=0;
	scanf(" %[^\n]",name1);
	int n=strlen(name1);
	scanf(" %[^\n]",name2);
	int k=strlen(name2);
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<k;j++)
	    {
	        if(tolower(name1[i])==tolower(name2[j]) && name2[i]!= '*')
	        {
	            name1[i] = '*';
	            name2[j] = '*';
	            break;
	        }
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    if(name1[i]!= '*')
	    {
	        count++;
	    }
	}
	
	for(int i=0;i<k;i++)
	{
	    if(name2[i]!= '*')
	    {
	        count++;
	    }
	}
	
	
	char flames[] = "FLAMES";
	int len = 6;
	int index = 0;
	
	while(len>1)
	{
	    index = (index + count -1) % len;
	    for(int i=index;i<len-1;i++)
	    {
	        flames[i] = flames[i+1];
	    }
	    len--;
	}
	
	switch(flames[0])
	{
	    case 'F': 
	        printf("Friends");
	        break;
	    case 'L': 
	        printf("Love");
	        break;
	    case 'A': 
	        printf("Affection");
	        break;
	    case 'M': 
	        printf("Marriage");
	        break;
	    case 'E': 
	        printf("Enemy");
	        break;
	    case 'S': 
	        printf("Sister");
	        break;
	    default: 
	        printf("Friends");
	        break;
	}
}

