#include<stdio.h>
#include<math.h>
unsigned Fac( int n);
double Mypow( int x, int n);
double CalculateE(int x, int number );

int main()
{
    int x;
    int  num;
//    printf("please input x:");
    scanf("%d",&x);
//    printf("please input the number of items:");
    scanf("%d",&num);
    
    printf("%.2f\n",CalculateE(x,num));
    
    return 0;
}

unsigned Fac( int n)
{
    unsigned int  result=1;
    for(int i=1;i<=n;i++)
        result*=i;
    return result;
}
double Mypow( int x, int n)
{
    if(n==0)
        return 1;
    else
        return x*Mypow(x,n-1);
    
    //int i;
    //double s=1;
    //for( i=1;i<=n;i++)
    //	s*=x;
    //return s;
}
double CalculateE(int x, int number )
{
    double sum=1,temp=1;
    int n=1;
    while(n<number)
    {
        temp=Mypow(x,n)/Fac(n);
        sum+=temp;
        n++;
    }
    return sum;
}

