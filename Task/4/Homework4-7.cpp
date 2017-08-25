#include<stdio.h>//输入3，输出 0.141 和 9
#include<math.h>
int main()
{
	int n = 1, count = 1;
	double sum, term, x;   		/*因为位数多，所以定义为双精度*/
	scanf("%lf", &x);
	sum = x;
	term = x;          			/*赋初值*/
	do
	{
		term = -term * x * x / ((n + 1) * (n + 2));
		sum += term;     	/*累加*/
		n += 2;
		count++;
	} while (fabs(term) >= 1e-5);
	printf("%.3lf\n%d \n", sum, count);
	return 0;
}

