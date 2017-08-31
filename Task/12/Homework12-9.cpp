#include<stdio.h>
#include<stdlib.h>

void packCharacters(char a, char b);

int main()
{
	char a, b;
	scanf("%c %c", &a, &b);
	packCharacters(a, b);
	return 0;
}

void packCharacters(char a, char b)
{
	unsigned displaymask = 1 << 15;
	unsigned contract;
	char c1, c2;
	int c;
	c1 = a;
	c2 = b;
	contract = a;
	contract <<= 8;
	printf("\n\'%c\' in bits as an unsigned integers is:\n",a);
	printf("%10u = ", a);
	for (c = 0; c < 8; c++)
		putchar('0');
	putchar(' ');
	for (c = 1; c <= 8; c++)
	{
		putchar(a&displaymask ? '1' : '0');
		a <<= 1;
	}
	printf("\n\'%c\' in bits as an unsigned integers is:\n", b);
	printf("%10u = ", b);
	for (c = 0; c < 8; c++)
		putchar('0');
	putchar(' ');
	for (c = 1; c <= 8; c++)
	{
		putchar(b&displaymask ? '1' : '0');
		b <<= 1;
	}
	printf("\n\'%c\' and \'%c\' packed in an unsigned integer:\n", c1, c2);
	contract = contract | c2;
	printf("%10u = ", contract);
	for (c = 1; c <= 16; c++)
	{
		putchar(contract&displaymask ? '1' : '0');
		contract <<= 1;
		if (c % 8 == 0)
			putchar(' ');
	}
}