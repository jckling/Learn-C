#include<stdio.h>
int main()
{
	int i, j, k;
	for (i = 5; i > 0; i--)
	{
		for (j = 1; j < i; j++)
			printf(" ");
		for (k = 1; k <= i; k++)
			printf("%d", i);
		printf("\n");
	}
	return 0;
}