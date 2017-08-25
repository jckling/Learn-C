#include <stdio.h>
#include<math.h>
int main( )
{
    int n;
    int u[20][20];
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&u[i][j]);
    int sum=0;
    for(i=0;i<n;i++)
        sum=sum+u[i][i];
    for(i=0;i<n;i++)
        sum=sum+u[i][abs(i-n+1)];
    if(n%2!=0)
        sum=sum-u[(n-1)/2][(n-1)/2];
    printf("%d",sum);
    return 0;
}

