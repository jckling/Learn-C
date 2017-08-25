#include<stdio.h>

int MaxCommonFactor(int a, int b);

int main()
{
    int a, b, x;
    
//    printf("Input a,b:");
    scanf("%d%d",&a,&b);
    
    x = MaxCommonFactor(a,b);
    printf("%d\n", x);
}
/*
 函数功能：   计算两个正整数的最大公约数
 函数入口参数：两个整型数
 函数返回值： 最大公约数；-1表示没有最大公约数
 */
int MaxCommonFactor(int a, int b)
{
    if (a <=0 || b <=0)		/* 保证输入的参数正确*/
        return -1;
    
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else if (b > a)
        {
            b = b - a;
        }
    }
    return a;
}
