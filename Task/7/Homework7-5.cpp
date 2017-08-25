#include<stdio.h>
int main()
{
	int a[10];
	int i, j, k, t, counter;
	int flag;
	counter = 0;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (j = 0; j < 9; j++)
	{
		flag = 0;
		for (i = 0; i < 9 - j-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				k = a[i];
				a[i] = a[i + 1];
				a[i + 1] = k;
				flag = 1;
			}
			counter++;
		}
		printf("After pass %d :", j);
		for (t = 0; t < 10 - j; t++)
			printf("%4d", a[t]);
		printf("\n");
		if (flag == 0)
			break;
	}
		printf("Data items in ascending order\n");
		for (i = 0; i < 10; i++)
			printf("%4d", a[i]);
		printf("\nNumber of comparisons = %d\n",counter);
		return 0;
	}