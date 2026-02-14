#include <stdio.h>
#include<string.h>

void scientificNotation(char input[])
{
    char base[1000];
    int i=0, j=0;
    
    while(input[i]!='e' && input[i]!='E')
    {
        base[j++] = input[i++];
    }
    base[j]='\0';
    i++;
    
    int sign=1;
    int expo=0;
    
    if(input[i]=='-')
    {
        sign= -1;
        i++;
    }
    else if(input[i]=='+')
    {
        sign=1;
        i++;
    }
    
    while(input[i]!='\0')
    {
        expo = expo*10 + (input[i]-'0');
        i++;
    }
    
    expo = expo*sign;
    
    int decimalIdx = -1;
    int len = strlen(base);
    for(int k=0;k<len;k++)
    {
        if(base[k]=='.')
        {
            decimalIdx=k;
            break;
        }
    }
    
    if(decimalIdx== -1)
    {
        decimalIdx=len;
    }
    
    char digits[1000];
    int index=0;
    
    for(int k=0;k<len;k++)
    {
        if(base[k]!='.')
        {
            digits[index++] = base[k];
        }
    }
    digits[index] = '\0';
    
    int digit_len = strlen(digits);
    int new_pos = decimalIdx + expo;
    
    if(new_pos>=digit_len)
    {
        printf("%s", digits);
        for(int k=0;k<new_pos-digit_len;k++)
        {
            printf("0");
        }
    }
    else if(new_pos>0)
    {
        for(int k=0;k<digit_len;k++)
        {
            if(k==new_pos)
            {
                printf('.');
            }
            printf("%c", digits[k]);
        }
    }
    else
    {
        printf("0.");
        for(int k=0;k<(-new_pos);k++)
        {
            printf("0");
        }
        printf("%s", digits);
    }
}

int main() {
	char input[1000];
	scanf("%s", input);
	
	scientificNotation(input);

}

