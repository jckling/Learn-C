#include<stdio.h>
int CommonFactors(int, int);
int MaxCommonFactor(int, int);
int main()
{
	int a, b, i;
	static int c;
	i = 1;
	scanf("%d %d", &a, &b);
	do
	{
		c = CommonFactors(a, b);
		if (c > 1)
		{
			printf("Common factor %d is %d\n", i, c);
			i++;
		}
	} while (c != -1);
	printf("Common factor %d is 1", i);
	return 0;
}

int CommonFactors(int a, int b)
{
	static int x;
	if (x == 0)
		return x = MaxCommonFactor(a, b);
	else
	{
		if (x % 2 == 0)
			return x = x / 2;
		else
			return -1;
	}

}

int MaxCommonFactor(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return MaxCommonFactor(b, a%b);
}