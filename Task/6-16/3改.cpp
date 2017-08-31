#include<stdio.h>
#include<math.h>
void p(int x);
int main()
{
	int x;
	scanf("%d", &x);
	p(x);
}
void p(int x)
{
	int i, flag = 1;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			printf("%d*%d", i, x / i);
			flag = 0;
			break;
		}
	}
	if (flag)
		printf("y");
}