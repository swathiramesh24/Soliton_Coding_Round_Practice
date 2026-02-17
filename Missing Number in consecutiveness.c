#include <stdio.h>
#include<string.h>

int getNumber(char s[], int l, int r)
{
    int num=0;
    for(int i=l;i<=r;i++)
    {
        num = num*10+(s[i]-'0');
    }
    return num;
}

int getDigits(long long n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n=n/10;
    }
    return c;
}

int main() {
    char s[100];
    scanf("%s", s);
    
    int n = strlen(s);
    
    for(int len=1;len<=n/2;len++)
    {
        long long prev = getNumber(s,0,len-1);
        int i = len;
        
        while(i<n)
        {
            long long expected = prev+1;
            int d = getDigits(expected);
            
            if(i+d-1>=n) break;
            
            long long current = getNumber(s,i,i+d-1);
            
            if(current==expected)
            {
                prev = current;
                i += d;
            }
            
            else
            {
                long long miss = prev+1;
                long long nextExpected = prev+2;
                int d2=getDigits(nextExpected);
                
                if(i+d2-1>=n) break;
                
                long long nextCurrent = getNumber(s,i,i+d2-1);
                
                if(nextCurrent==nextExpected)
                {
                    printf("%lld", miss);
                    return 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return 0;
}

