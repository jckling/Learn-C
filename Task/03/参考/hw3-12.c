#include <stdio.h>
#include <math.h>
#define LIMIT  1e-5

int main()
{
    float a, b, c;
    int flag = 1;
    
   // printf("Input the three edge length: ");
    scanf("%f, %f, %f", &a, &b , &c);		/*输入三角形的三条边*/
    /*三角形的基本条件*/
    if ((a + b) > c && ((b + c) > a) && ((a + c) > b))
    {
        if (fabs(a-b) <= LIMIT 	|| fabs(b-c) <= LIMIT
            || fabs(c-a) <= LIMIT)          	/*等腰三角形的条件*/
        {
            printf("等腰");
            flag = 0;
        }
        if (fabs(a * a + b * b - c * c) <= LIMIT
            || fabs(a * a + c * c - b * b) <= LIMIT
            || fabs(c * c + b * b - a * a) <= LIMIT) /*直角三角形的条件*/
        {
            printf("直角");
            flag = 0;
        }
        if (flag)
        {
            printf("一般");
        }
        printf("三角形\n");
    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}



