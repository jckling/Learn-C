#include <stdio.h>
int main()
{
	int  a, b, i, k;
	scanf("%d", &a);
	for (b = 0; b < a; b++)
	{
		for (k = 1; k < a-b; k++)
		printf(" ");
        for (i = 0; i <= 2 * b; i++)
		printf("*");
		printf("\n");
	}
	return 0;
}