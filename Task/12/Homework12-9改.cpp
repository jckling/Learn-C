#include<stdio.h>
void print(int a);
unsigned pow(char a, char b);
int main()
{
	char a, b;
	scanf("%c %c", &a, &b);
	printf("\n\'%c\' in bits as an unsigned integers is:\n", a);
	print(a);
	printf("\n\'%c\' in bits as an unsigned integers is:\n", b);
	print(b);
	printf("\n\'%c\' and \'%c\' packed in an unsigned integer:\n", a, b);
	print(pow(a, b));
}
unsigned pow(char a, char b)
{
	unsigned i = a;
	i <<= 8;
	return i|b;
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