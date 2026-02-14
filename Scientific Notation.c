#include <stdio.h>
#include<string.h>

void convert(char* input)
{
    char base[10000];
    int i=0,j=0;
    while(input[i]!='e' && input[i]!='E')
    {
        base[j++]=input[i++];
    }
    base[j]='\0';
    i++;
    
    int sign=1;
    if(input[i]=='-')
    {
        sign = -1;
        i++;
    }
    else if(input[i]=='+')
    {
        i++;
    }
    
    int expo =0;
    while(input[i]!='\0')
    {
        expo = expo*10 + (input[i] - '0');
        i++;
    }
    expo *= sign;
    
    int decimalIndex = -1;
    int len = strlen(base);
    for(int k=0;k<len;k++)
    {
        if(base[k]=='.')
        {
            decimalIndex = k;
            break;
        }
    }
    
    if(decimalIndex==-1)
    {
        decimalIndex=len;
    }
    
    char digits[10000];
    int index = 0;
    for(int k=0;k<len;k++)
    {
        if(base[k]!='.')
        {
            digits[index++] = base[k];
        }
    }
    digits[index]='\0';
    int digits_len = strlen(digits);
    int new_pos = expo+decimalIndex;
    
    printf("Output\n");
    if(new_pos>=digits_len)
    {
        printf("%s", digits);
        for(int k=0;k<new_pos- digits_len;k++)
        {
            printf("0");
        }
    }
    else if(new_pos>0)
    {
        for(int k=0;k<new_pos;k++)
        {
            printf("%c", digits[k]);
            printf(".");
        }
        for(int k=new_pos;k<digits_len;k++)
        {
            printf("%c", digits[k]);
        }
    }
    else
    {
        printf("0. ");
        for(int k=0;k< (-1*new_pos);k++)
        {
            printf("0");
        }
        printf("%s", digits);
    }
}

int main() {
	convert("1.23e5");

}

