#include <stdio.h>

int main() {
	char word[50];
	scanf("%[^\n]", &word);
	int n = strlen(word);

	int start = 0;
	int end = n-1;
	
	while(start<end)
	{
	    if(word[start]== ' ')
	    {
	        start++;
	        continue;
	    }
	    
	    if(word[end]== ' ')
	    {
	        end--;
	        continue;
	    }
	    
	    if(word[start]!=word[end])
	    {
	        printf("False");
	        return 0;
	    }
	    start++;
	    end--;
	}
	printf("True");

}

