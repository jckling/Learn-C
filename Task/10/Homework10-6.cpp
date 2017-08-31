#include<stdio.h>
#include<math.h>

double calc(double(*funp)(double), double a, double b);
double x(double a);
double y(double a);

int main()
{
	printf("%.4lf\n", calc(x, 0, 1));
	printf("%.4lf", calc(y, 1, 2));
	return 0;
}

double x(double a)
{
	return a * a;
}

double y(double a)
{
	return sin(a) / a;
}

double calc(double(*funp)(double), double a, double b)
{
	return (b - a) / 2 * (funp(a) + funp(b));
}