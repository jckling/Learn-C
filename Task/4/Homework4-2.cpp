#include<stdio.h>//4039.44
int main()
{
	double a, b;
	int i;
	a = 1000.0;
	b = a / (1 + 12 * 0.0063);
	for (i = 2; i < 6; i++)
		b = (b + 1000) / (1 + 12 * 0.0063);
	printf("%.2lf", b);
	return 0;
}
			

