#include<stdio.h>
int X(int);
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d", X(a));
	return 0;
}
int X(int x)
{
	int a, b, c, d;
	int i;
	a = b = c = 1;
	if (x == 1 || x == 2 || x == 3)
		return 1;
	else
	{
		for (i = 0; i < (x-3); i++)
		{
			d = a + b + c;
			a = b;
			b = c;
			c = d;
		}
		return d;
	}



}