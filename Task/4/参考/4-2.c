#include<stdio.h>

int main()
{
    int i;
    double saving=0;
    for(i=1;i<=5;i++)		//i 为年数，取值为-5年
    {
        saving=(saving+1000)/(1+0.0063*12);		//累计算出年初存款数额，第五次的计算结果即为题解
    }
    //printf("He must save %.2f at first.\n",saving);
    printf("%.2f",saving);
    
    return 0;
}
