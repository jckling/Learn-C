#include<stdio.h>
void power2(int number, int pow);
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	power2(a, b);
	return 0;
}
void power2(int number, int pow)
{
	unsigned displaymask = 1 << 15;
	unsigned int a, b, c, s;
	s = a = number;
	b = pow;
	for (c = 0; c < b; c++)
		s *= 2;
	printf("number:\n");
	printf("%10u = ",number);
	for (c = 1; c <= 16; c++)
	{
		putchar(number&displaymask ? '1' : '0');
		number <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
	printf("\npow:\n");
	printf("%10u = ", pow);
	for (c = 1; c <= 16; c++)
	{
		putchar(pow&displaymask ? '1' : '0');
		pow <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
	printf("\n%u * 2^%u = %u\n", a, b, s);
	printf("%10u = ", s);
	for (c = 1; c <= 16; c++)
	{
		putchar(s&displaymask ? '1' : '0');
		s <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}

}