#include <stdio.h>
#include<string.h>


void smallestPalindrome(char * str)
{
    int freq[26] = {0};
    int len = strlen(str);
    
    for(int i=0;i<len;i++)
    {
        freq[str[i]-'a']++;
    }
    int odd_count = 0;
    char ch = '\0';
    
    for(int i=0;i<26;i++)
    {
        if(freq[i]%2!=0)
        {
            odd_count++;
            ch = (char)(i+'a');
        }
    }
    
    if(odd_count>1)
    {
        printf("Not Possible");
        return;
    }
    
    char left[1000] = "";
    int index = 0;
    for(int i=0;i<26;i++)
    {
        int pair = freq[i]/2;
        for(int j=0;j<pair;j++)
        {
            left[index++] = (char)(i+'a');
        }
    }
    left[index] = '\0';
    printf("Smallest Palindrome ");
    printf("%s", left);
    if(ch!='\0')
    {
        printf("%c", ch);
    }
    
    for(int i=index-1;i>=0;i--)
    {
        printf("%c", left[i]);
    }
    printf("\n");
}

int main() {
    smallestPalindrome("aabb");
}

