#include<stdio.h>
#include<math.h>
int main()
{
	double a, b;
	int c;
	scanf("%lf", &a);
	b = a + 0.5;
	c = int(b);
	printf("%d\n", c);
	printf("%.1f\n", a);
	printf("%.2f\n", a);

	return 0;
}