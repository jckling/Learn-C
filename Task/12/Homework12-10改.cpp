#include<stdio.h>
void print(int a);
void pow(unsigned a);
int main()
{
	unsigned a;
	scanf("%d", &a);
	print(a);
	pow(a);
}
void pow(unsigned a)
{
	unsigned mask1, mask2;
	char x, y;
	mask1 = 65280;
	mask2 = 255;
	x = (mask1&a)>>8;
	y = mask2&a;
	printf("\nThe unpacked characters are \'%c\' and \'%c\'\n", x, y);
	print(x);
	printf("\n");
	print(y);
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