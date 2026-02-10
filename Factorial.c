#include <stdio.h>
int fact(int n)
{
   
    if(n==0 || n==1)
    return 1;
    
    return n*fact(n-1);
}

int main() {
	int n;
	scanf("%d",&n);
	
	if(n<0)
    {
    printf("Undefined\n");
    return 0;
    }
    

    
	int res=fact(n);
	printf("%d",res);
}

