#include<stdio.h>
#include<math.h>
int Prime(int);
void W(int);
int main()
{
	int x;
	scanf("%d", &x);
	if (Prime(x))
		printf("y");
	else
		W(x);
	return 0;
}

int Prime(int x)
{
	int i;
	double n;
	n = sqrt(double(x));
	for (i = 2; i <= n; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
void W(int a)
{
	int i = 2;
	while (a%i != 0)
		i++;
	printf("%d*%d", i, a / i);

}