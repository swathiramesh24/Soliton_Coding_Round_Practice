#include <stdio.h>

int findBreakPoint(char num[], int len)
{
    for(int i=len-2;i>=0;i--)
    {
        if(num[i]>num[i+1])
        {
            return i;
        }
    }
    return -1;
}

int findSwapIndex(char num[], int breakPoint, int len)
{
    int index = breakPoint;
    for(int i=breakPoint+1;i<len;i++)
    {
        if(num[i]<num[breakPoint])
        {
            index=i;
        }
    }
    return index;
}

void swapValues(char* num, int breakPoint, int swapIndex)
{
    char temp = num[breakPoint];
    num[breakPoint] = num[swapIndex];
    num[swapIndex] = temp;
}

void reverse(char* num, int start, int end)
{
    while(start<end)
    {
        swapValues(num, start, end);
        start++;
        end--;
    }
}

int main() {
    char num[100];
    scanf("%s", num);
    int len = strlen(num);
    
    int breakPoint = findBreakPoint(num, len);
    
    if(breakPoint<0)
    {
        printf("Cannot be found");
        return 0;
    }
    
    int swapIndex = findSwapIndex(num, breakPoint, len);
    swapValues(num, breakPoint, swapIndex);
    reverse(num, breakPoint+1, len-1);
    printf("%s\n", num);
    return 0;
}

