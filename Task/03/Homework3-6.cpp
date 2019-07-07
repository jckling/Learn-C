#include<stdio.h>//1!+2!+3!+4!+¡­+10£¡= 4037913
int main()
{
	unsigned a = 1, b = 1, c = 0;

	while (a <= 10)
	{
		b *= a;
		c += b;
		a++;
	}
	printf("%ld", c);
	return 0;
}