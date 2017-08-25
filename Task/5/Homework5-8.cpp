#include<stdio.h>
int MaxCommonFactor(int, int);
int main()
{
	int a, b;
		scanf("%d%d", &a, &b);
	    printf("%d", MaxCommonFactor(a, b));
	return 0;
}
int MaxCommonFactor(int x, int y)
{

	do
	{
		if (x > y)
			x -= y;
		else if (x < y)
			y -= x;
	} while (x != y);
	return x;
}