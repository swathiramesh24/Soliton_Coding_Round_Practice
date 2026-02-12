#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int part = n/7;
	
	int first = 4*part;
	int second = 2*part;
	int third = part;
	
	printf("%d\n%d\n%d\n", first,second,third);
	return 0;
}

