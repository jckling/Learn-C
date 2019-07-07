#include<stdio.h>//=1/(1+2+3)-2/(2+3+4)+3/(3+4+5)-4/(4+5+6)+……的前20项之和为 -0.094537
int main()
{
	double sum = 0;
	int a = 1, b;
	while (a <= 20)
	{
		b = 3 * a + 3;
		if (a % 2 == 0)
			sum += -1.0 * a / b;
		else
			sum += 1.0 * a / b;
		a++;
	}
    printf("%lf", sum);
	return 0;
}