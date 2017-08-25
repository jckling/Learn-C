#include<stdio.h>
#include<math.h>
int main()
{
	int number[10];
	int min, x;
	int i;
	scanf("%d", &number[0]);
	min = number[0];
	for (i = 1; i < 10; i++)
	{
		scanf("%d", &number[i]);
		x = fabs(number[i]);
		if (fabs(min) > x)
			min = number[i];
	}
	printf("%d", min);

		return 0;
}