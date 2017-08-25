#include <stdio.h>
#include <math.h>
/* 计算数值积分（函数指针作为函数参数示例） */
double f1(double);
double f2(double);
double calc(double (*funp)(double), double a, double b);
int main(void)
{  double result;
    double (*funp)(double);
    result = calc(f1, 0.0, 1.0);        /* 函数名f1作为函数calc的实参 */
    printf("%.4f\n", result);
    funp = f2;               		/* 对函数指针funp赋值 */
    result = calc(funp, 1.0, 2.0);     /* 函数指针funp作为函数calc的实参 */
    printf("%.4f\n", result);
    return 0;
}
/* 函数指针funp作为函数的形参 */
double calc(double (*funp)(double), double a, double b)
{
    double z;
    z = (b-a)/2 * ((*funp)(a) + (*funp)(b));   /* 调用funp指向的函数 */
    return(z);
}
double f1(double x)
{
    return x*x;
}
double f2(double x)
{
    return sin(x)/x;
}
