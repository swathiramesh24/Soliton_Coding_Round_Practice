#include <stdio.h>

void countVowelsConsonants(char str[], int *vowels, int *consonants) {
    int n = strlen(str);
    for(int i=0;i<n;i++)
    {
        int ch = str[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            *vowels += 1;
        }
        else if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
        {
            *vowels += 1;
        }
        else
        {
            *consonants += 1;
        }
    }
}

int main()
{
    char str[10000];
    scanf("%[^\n]", str);
    
    int vowels,consonants;
    
    countVowelsConsonants(str, &vowels, &consonants);
    printf("%d\n%d", vowels, consonants);
}
