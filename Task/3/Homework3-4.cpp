#include<stdio.h>
#include<math.h>
int main()
{
	double x;
	scanf("%lf",&x);

	if (x > 0)
		printf("y=%g", exp(-x));
	else if (x < 0)
		printf("y=%g", -exp(x));
	else
		printf("y=1");
	return 0;
}