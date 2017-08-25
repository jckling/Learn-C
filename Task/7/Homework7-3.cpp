#include<stdio.h>
int main()
{
	int a[10];
	int i, j, k, t, counter;
	counter = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (j = 0; j < 9; j++)
	{
		for (i = 0; i < 9 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
			}
			counter++;
		}
		printf("After pass %d :", j);
		for (t = 0; t < 10 - j; t++)
			printf("%4d", a[t]);
		printf("\n");
	}
		printf("Data items in ascending order\n");
		for (i = 0; i < 10; i++)
			printf("%4d", a[i]);
		printf("\nNumber of comparisons = %d\n",counter);
		return 0;
	}