#include<stdio.h>
int CommonFactors(int a, int b);
int main()
{
	int a, b;
	int i = 1, k;
	scanf("%d %d", &a, &b);
	k = CommonFactors(a, b);
	while (k != -1)
	{
		printf("Common factor %d is %d\n", i, k);
		k = CommonFactors(a, b);
		i++;
	}
}
int CommonFactors(int a, int b)
{
	static int i;
	if (i == 0)
	{
		if (a % b == 0)
			return i = b;
		else
			return CommonFactors(b, a % b);
	}
	else
	{
		if (i % 2 == 0)
			return i = i / 2;
		else
			return -1;
	}
}