#include <stdio.h>

int MinCommonMultiple(int a, int b);

int main()
{
    int a, b, x;
    
    //printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    
    x = MinCommonMultiple(a,b);
    printf("%d\n", x);
    
    return 0;
}
/*
 函数功能：   计算两个正整数的最小公倍数
 函数入口参数：两个整型数
 函数返回值： 最小公倍数
 */
int MinCommonMultiple(int a, int b)
{
	int i;
    for (i=1; i<b; i++)
    {
        if ((i*a) % b == 0)
            return i*a;
    }
    return b*a;
}
