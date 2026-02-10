#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int reversed = 0;
	
	while(n!=0)
	{
	    int l = n%10;
	    reversed = (reversed * 10) + l;
	    n=n/10;
	}
	printf("%d", reversed);

}

