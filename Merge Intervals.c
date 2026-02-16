#include <stdio.h>

typedef struct
{
    long long start;
    long long end;
} Interval;

void swap(Interval *a, Interval *b)
{
    Interval t = *a;
    *a = *b;
    *b = t;
}

void sortInterval(Interval arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIdx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j].start < arr[minIdx].start)
            {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Interval arr[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld", &arr[i].start, &arr[i].end);
    }
    
    sortInterval(arr,n);
    
    Interval merged[n];
    int m =0;
    merged[0] = arr[0];
    m=1;
    
    for(int i=1;i<n;i++)
    {
        if(arr[i].start <= merged[m-1].end+1)
        {
            if(arr[i].end > merged[m-1].end)
            {
                merged[m-1].end = arr[i].end;
            }
        }
        else
        {
            merged[m++] = arr[i];
        }
    }
    
    long long maxRange = -1;
    int idx=0;
    for(int i=0;i<m;i++)
    {
        long long range = merged[i].end - merged[i].start;
        if(range>maxRange)
        {
            maxRange = range;
            idx = i;
        }
    }
    
    printf("[%lld,%lld]", merged[idx].start, merged[idx].end);
    return 0;
}

