#include<stdio.h>
int main()
{
	int a, m, n, i, k;
	scanf("%d", &a);
	for (m = 0; m < a; m++)
	{
		for (n = 0; n < a; n++)
		{
			k = (m + n) % a;
			for (i = 0; i < a; i++)
				printf("%d", (k + i) % a + 1);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}