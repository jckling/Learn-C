#include<stdio.h>

void print(int a);
unsigned pow(unsigned a, unsigned b);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("number:\n");
	print(a);
	printf("\npow:\n");
	print(b);
	printf("\n%d*2^%d=%d\n", a, b, pow(a, b));
	print(pow(a, b));
}

unsigned pow(unsigned a, unsigned b)
{
	return a << b;	
}

void print(int a)
{
	unsigned mask = 1 << 15;
	int i;
	printf("%10u=", a);
	for (i = 1; i <= 15; i++)
	{
		putchar(a&mask ? '1' : '0');
		a <<= 1;
		if (i % 8 == 0)
			putchar(' ');
	}
}