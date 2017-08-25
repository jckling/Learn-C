#include<stdio.h>
#include<math.h>

void godbaha(int );
int prime(int);

int main()
{
    int n;
    do
    {
       // printf("Please input an even number which is bigger than 6:");
        scanf("%d",&n);
    }while(n%2!=0 || n<6);
    godbaha(n);
    return 0;
}

void godbaha(int n)
{
    int a,b;
    for(a=3;a<=n/2;a=a+2)  //a不能是偶数,否则b也是偶数,所以a取值为3，且每次加2
    {
        if(prime(a))
        {
            b=n-a;
            if(prime(b))
                printf("%d=%d+%d\n",n,a,b);
        }
    }
}

int prime(int m)
{
    int i,flag=1,k=sqrt((double)m);
    for(i=2;i<=k && flag;i++)
        if(m%i==0)
            flag=0;
    return flag;
}
