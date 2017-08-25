#include <stdio.h>

int MaxCommonFactor(int a, int b);

int main()
{
    int a, b, x;
    
    //printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    
    x = MaxCommonFactor(a,b);
    printf("%d\n", x);
    
    return 0;
}
/*
 函数功能：   计算两个正整数的最大公约数
 函数入口参数：两个整型数
 函数返回值： 最大公约数
 */
int MaxCommonFactor(int a, int b)
{
    int r;
	if (b > a)
	{
		r = b;
		b = a;
		a = r;
	}
    do{
        r = a % b;
        a = b;
        b = r;
    }while (r != 0);

    return  a;
}
