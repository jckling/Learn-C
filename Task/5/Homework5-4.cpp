#include<stdio.h>
void p(double, double);

int main()
{
	double m, k;
	do
	{
		scanf("%lf,%lf", &m, &k);		
	} while (m < k  || k <= 0);
       p(m, k);
	return 0;
}

void p(double a, double b)
{
	double result;
	double c,j,n,k;
	j = n = k = 1;
	c = a - b;
	for (; a > 0; a--)
		j *= a;
	for (; b > 0; b--)
		n *= b;
	for (; c > 0; c--)
		k *= c;

	result = j / n / k;
	printf("%0.2lf", result);

}