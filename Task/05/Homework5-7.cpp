#include<stdio.h>
#include<math.h>
double Fac(unsigned int);
int Mypow(int, int);
void CalculateE(int, int);

int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	CalculateE(a, b);
	return 0;
}
double Fac(unsigned int x)
{
	if (x == 1)
		return 1;
	else
		return Fac(x - 1) * x;
}
int Mypow(int x, int y)
{
	return pow(x, y);
}
void CalculateE(int x, int y)
{
	double result = 1.0;
	int n;
	for (n = 1; n < y; n++)
		result += Mypow(x, n) / Fac(n);
	printf("%.2lf", result);
}