#include<stdio.h>
#include<math.h>
void unpackCharacters(int x);
int main()
{
	unsigned x;
	scanf("%u", &x);

	unpackCharacters(x);

	return 0;
}
void unpackCharacters(int x)
{
	unsigned displaymask = 1 << 15;
	unsigned mask1 = 65280 << 31;
	unsigned mask2 = 255 << 31;
	unsigned y, z;
	int c, a, b, n, m;
	z = y = x;
	m = n = pow(2,7);
	a = b = 0;
	printf("%10u = ", x);
	for (c = 1; c <= 16; c++)
	{
		putchar(y&displaymask ? '1' : '0');
		if (c <= 8)
		{
			a += ((y&displaymask ? '1' : '0') - '0')*n;
			n /= 2;
		}
		else
		{
			b += ((y&displaymask ? '1' : '0') - '0')*m;
			m /= 2;
		}
		y <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
	printf("\nThe unpacked characters are \'%c\' and \'%c\'\n", a, b);
	printf("%10u = ", a);
	for (c = 1; c <= 16; c++)
	{
		putchar(a&displaymask ? '1' : '0');
		a <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
	printf("\n%10u = ", b);
	for (c = 1; c <= 16; c++)
	{
		putchar(b&displaymask ? '1' : '0');
		b <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
}