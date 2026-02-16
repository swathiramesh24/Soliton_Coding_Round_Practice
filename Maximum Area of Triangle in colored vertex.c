#include<stdio.h>
#include<math.h>

#define MAXN 2000

typedef struct
{
    long long x,y;
} Point;

int findAbs(int num)
{
    if(num<0)
    {
        return -1*num;
    }
    return num;
}

double findArea(Point a, Point b, Point c)
{
    long long val = a.x * (b.y-c.y) + 
                    b.x*(c.y-b.y)+
                    c.x*(a.y-b.y);
    return findAbs(val)/2.0;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    Point color[3][MAXN];
    int count[3] = {0,0,0};
    
    for(int i=0;i<N;i++)
    {
        long long x,y;
        int c;
        scanf("%lld %lld %d", &x,&y,&c);
        
        color[c][count[c]].x=x;
        color[c][count[c]].y=y;
        count[c]++;
    }
    
    if(count[0]==0 || count[1]==0 || count[2]==0)
    {
        printf("0.0\n");
        return 0;
    }
    
    double maxArea = 0.0;
    
    for(int i=0;i<count[0];i++)
    {
        for(int j=0;j<count[1];j++)
        {
            for(int k=0;k<count[2];k++)
            {
                double currArea = findArea(
                        color[0][i],
                        color[1][j],
                        color[2][k]
                        );
                        
                if(currArea>maxArea)
                {
                    maxArea=currArea;
                }
            }
        }
    }
    
    printf("%.1f\n", maxArea);
    return 0;
}
