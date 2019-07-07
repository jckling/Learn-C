#include<stdio.h>
#include<math.h>
void fun(double x, double y, double *c, double *q);
int main()
{
	double x, y, a, b;
	scanf("%lf%lf", &x, &y);
	fun(x, y, &a, &b);
	printf("%.2lf %.2lf", a, b);
}
void fun(double x, double y, double *c, double *q)
{
	if (x != 0)
	{
		*c = sqrt(x*x + y*y);
		*q = atan(y / x);
	}
	else if (y != 0) { *c = fabs(y); *q = 1.57; }
	else { *c = 0; *q = 0; }
	return;
}