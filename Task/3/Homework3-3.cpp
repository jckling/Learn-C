#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);

	if (a > 0)
	{
		if (a % 2 == 0)
			printf("%d is a positive even", a);
		else
			printf("%d is a positive odd", a);
	}
	else if (a < 0)
	{
		if (a % 2 == 0)
			printf("%d is a negative even", a);
		else
			printf("%d is a negative odd", a);
	}
	else
		printf("%d is zero",a);

	return 0;


}