/*
Given the elements of an array A[] convert it to an integer, add 1 to the result and
print. The most significant digit is moved to the first element of the array.
Input: 1 2 3
Output: 124
Input: 0 8
Output: 9
Approach: Array size will not be given so initialize array of size of your choice and
then get inputs and perform operation, result += result * 10 + array[i].
*/

#include <stdio.h>

int main() {
    int arr[100];
    int n=0;
    int result;
    
    while(scanf("%d", &arr[n])==1)
    {
        n++;
        if(getchar()=='\n')
        {
            break;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        result = result*10 + arr[i];
    }
    
    result=result+1;
    printf("%d", result);
    return 0;
}

