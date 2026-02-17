#include <stdio.h>

typedef struct
{
    long long value;
    long long freq;
}Node;

void merge(long long arr[], int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    
    long long left[n1];
    long long right[n2];
    
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=arr[m+1+j];
    }
    
    int i=0,j=0,k=l;
    while(i<n1 && i<n2)
    {
        if(left[i]<=right[j]) arr[k++]=left[i++];
        else arr[k++]=right[j++];
    }
    
    while(i<n1) arr[k++]=left[i++];
    while(j<n2) arr[k++]=right[j++];
}

void mergeSort(long long arr[], int l, int r)
{
    if(l<r)
    {
        int m=(r+l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void swap(Node *a, Node *b)
{
    Node t= *a;
    *a=*b;
    *b=t;
}

void sortNodes(Node arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j].freq>arr[i].freq || (arr[i].freq==arr[j].freq && arr[i].value>arr[j].value))
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld", &arr[i]);
    }
    
    mergeSort(arr,0,n-1);
    
    Node nodes[n];
    int count=0;
    
    long long current=arr[0];
    long long freq=1;
    
    for(int i=1;i<n;i++)
    {
        if(current==arr[i])
        {
            freq++;
        }
        else
        {
            nodes[count].value=current;
            nodes[count].freq=freq;
            count++;
            
            current=arr[i];
            freq=1;
        }
    }
    
    nodes[count].value=current;
    nodes[count].freq=freq;
    count++;
    sortNodes(nodes, count);
    
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<nodes[i].freq;j++)
        {
            printf("%lld ", nodes[i].value);
        }
    }
    return 0;
}

