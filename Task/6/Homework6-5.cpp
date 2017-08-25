#include<stdio.h>
int MaxCommonFactor(int, int);
int main()
{
	int a, b;
	int s;
	scanf("%d,%d", &a, &b);
	s = MaxCommonFactor(a, b);
	printf("%d", s);
	return 0;
}

int MaxCommonFactor(int a, int b)
{

	if (a%b == 0)
		return b;
	else
		return  MaxCommonFactor(b, a%b);

}