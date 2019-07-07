#include<stdio.h>
#include<math.h>
int main()
{
    int n = 1,count = 1;
    float x;
    double sum , term;   		/*因为位数多，所以定义为双精度*/
    
    //printf("Input x: ");
    scanf("%f",&x);
    sum = x;
    term = x;          			/*赋初值*/
    do
    {
        term = -term * x * x / ((n + 1) * (n + 2));
        sum = sum + term;       	/*累加*/
        n = n + 2;
        count++;
    }while (fabs(term) >= 1e-5);
    
    //printf("sin(x) =%f,count =%d \n",sum,count);
    printf("%f\n%d \n",sum,count);
    return 0;
}

