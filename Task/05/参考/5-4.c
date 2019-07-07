#include <stdio.h>

unsigned long Factorial(unsigned int number);

int main()
{
    unsigned int m, k;
    double p;
    
    do{
       // printf("Please input m, k(m>=k>0):");
        scanf("%u,%u", &m, &k);
    }while(m < k) ;
    
    p = (double)Factorial(m) / (Factorial(k) * Factorial (m-k));
    printf("%.2f\n", p);
    
    return 0;
}

/*
 函数功能：    计算参数的阶乘
 函数入口参数：无符号整型
 函数返回值：  运算结果
 */
unsigned long Factorial(unsigned int number)
{
    unsigned long i, result = 1;
    
    for (i=2; i<=number; i++)
        result *= i;
    
    return result;
}
