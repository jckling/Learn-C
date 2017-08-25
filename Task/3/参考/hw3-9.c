#include<stdio.h>
#include<math.h>
int main()
{
    int n = 1;
    double term = 1.0, sign = 1,sum = 0;
    
    while (fabs(term) >= 1e-4)		/*判断末项大小*/
    {
        term = sign / n;			/*求出累加项*/
        sum = sum + term;			/*累加*/
        sign = -sign;				/*改变项的符号*/
        n++;							/*分母加*/
    }
    printf("%lf\n",sum);
    
    return 0;
}
