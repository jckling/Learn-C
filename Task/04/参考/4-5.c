#include<stdio.h>

int main()
{
    int i,j,k,c;
    for(i=1;i<=9;i++)
        for(j=0;j<=9;j++)
            if(i!=j)
            {
                k=i*1000+i*100+j*10+j;
                for(c=32;c*c<=k;c++)   //31*31=961
                    if(c*c==k)
                        //printf("车牌号为：%d",k);
                        printf("%d",k);
            }
    return 0;
}
