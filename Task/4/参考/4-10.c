#include<stdio.h>

int main()
{
    int i,j,k,t,n;
    scanf("%d",&n);
    for(j=0;j<n;j++)			//构造n个不同的拉丁方阵
    {
        for(i=0;i<n;i++)
        {
            t=(i+j)%n;			//确定该拉丁方阵第i 行的第一个元素的值
            for(k=0;k<n;k++)	//按照环的形式输出该行中的各个元素
            {
                printf("%d",(k+t)%n+1);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}
