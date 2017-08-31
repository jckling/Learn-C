#include<stdio.h>
int main()
{
	double w, h, t;
	scanf("%lf%lf", &w, &h);

	t = w / h / h;
	printf("%lf\n", t);
	if (t < 18)
		printf("lower weight"); 
	else if (18 < t && t < 25)
		printf("normal weight");
	else if (t > 25 && t < 27)
		printf("higher weight");
	else
		printf("obesity");

	return 0;
}