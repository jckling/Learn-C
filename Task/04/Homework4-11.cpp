#include<stdio.h>
int main()
{
	char x;
	int m, n, j, i;
	i = 1;
	x = 'A';
	for (n = 9; n > 0; n--)
	{
		for (m = 1; m <= n; m++)
			printf("+");
		for (j = 1; j <= i; j++)
		{
			printf("%c", x);
			if (x < 'Z')
				x++;
			else
				x -= 25;
		}
		for (m = 1; m <= n; m++)
			printf("+");
		i += 2;
		printf("\n");
	}
	i = 15;
	for (n = 2; n <10; n++)
	{
		for (m = 1; m <= n; m++)
			printf("+");
		for (j = 1; j <= i; j++)
		{
			printf("%c", x);
			if (x < 'Z')
				x += 1;
			else
				x -= 25;
		}
		for (m = 1; m <= n; m++)
			printf("+");
		i -= 2;
		printf("\n");
	}
	return 0;
}