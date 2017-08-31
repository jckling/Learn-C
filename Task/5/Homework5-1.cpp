#include<stdio.h>
#include<math.h>
void hypotenuse(double, double);
int main()
{
	double a, b;
	int i;
	for (i = 1; i <= 3; i++)
	{
		scanf("%lf,%lf", &a, &b);
		hypotenuse(a, b);
	}

	return 0;
}
void hypotenuse(double x, double y)
{
	double n;
	n = sqrt(x * x + y * y);
	printf("Hypotenuse:%.1lf\n", n);
}

