#include <stdio.h>

int main() {
    int r;
    scanf("%d", &r);
    int c;
    scanf("%d", &c);
    
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=0;i<r;i++)
    {
        int freq[1000] = {0};
        int found = -1;
        for(int j=0;j<c;j++)
        {
            int val = arr[i][j];
            if(freq[val]>0)
            {
                found=val;
                break;
            }
            freq[val]++;
        }
        printf("%d\n", found);
    }
    
    return 0;
}

