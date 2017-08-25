#include<stdio.h>
#include<math.h>
int p(int a, int b);
int main()
{
	int a, b, t;
	scanf("%d %d", &a, &b);
	do
	{
		t = p(a, b);
		printf("%d\n", t);
	} while (t != 1);
}
int p(int a, int b)
{
	static int i;
	if (i == 0)
	{
		for (i = a; i > 0; i--)
		{
			if (a%i == 0 && b%i == 0)
				return i;
		}
	}
	else
		return i = i / 2;
}