#include<stdio.h>
int main()
{
	int i, j;
	for (i = 0, j = 1; i < 100; j++)
	{
		printf("%d\n", i);
		i += j;
	}
}