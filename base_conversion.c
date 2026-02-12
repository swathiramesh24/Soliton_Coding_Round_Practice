#include <stdio.h>

int findBase(char ch)
{
    if(ch=='D') return 10;
    else if(ch=='B') return 2;
    else if(ch=='H') return 16;
    else if(ch=='O') return 8;
    else return -1;
}

int integerValueOf(char ch)
{
    if(ch>='0' && ch<='9') return ch-48;
    else if(ch>='A' && ch<='F') return ch-55;
    else if(ch>='a' && ch<='f') return ch-87;
    else return -1;
}

int findDecimal(char input[], int convertFrom)
{
    int d=0;
    for(int i=0;input[i]!='\0';i++)
    {
        d = (d*convertFrom)+integerValueOf(input[i]);
    }
    return d;
}

char charValue(int rem)
{
    if(rem>=0 && rem<=9) return rem+48;
    else return rem+55;
}

void convertedResult(int decimalNumber, int convertTo)
{
    char res[100];
    int i=0;
    while(decimalNumber>0)
    {
        int rem = decimalNumber % convertTo;
        res[i]= charValue(rem);
        decimalNumber = decimalNumber/convertTo;
        i++;
    }
    
    for(int j=i-1;j>=0;j--)
    {
        printf("%c", res[j]);
    }
}

int main() {
	char fromIndex;
	char toIndex;
	char input[100];
	
	scanf(" %c", &fromIndex);
	scanf(" %c", &toIndex);
	scanf(" %[^\n]", input);
	
	int convertFrom = findBase(fromIndex);
	if(convertFrom==-1)
	{
	    printf("Enter valid type");
	    return 0;
	}
	
	int convertTo = findBase(toIndex);
	if(convertTo==-1)
	{
	    printf("Enter a valid type");
	    return 0;
	}
	
	int decimalNumber = findDecimal(input, convertFrom);
	
	convertedResult(decimalNumber, convertTo);
	return 0;

}

