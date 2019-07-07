#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    double y;
   // printf("please input an interger:");
    scanf("%d", &x);        /* 输入一个整数*/
    if (x > 0)
    {
        y = exp(-(double)x);  /*如果大于，计算y=exp(-x)的值*/
    }
    else if (x == 0)
    {
        y = 1;   /*x=0，则y=1*/
    }
    else
    {
        y = -exp((double)x);  /*x<0，则y=-exp(x)*/
    }
    printf("y=%g\n", y);
    
    return 0;
}
