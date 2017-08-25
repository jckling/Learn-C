#include<stdio.h>
void X(int, char, char);
int main()
{
	char b, c;
	int a;
	scanf("%d %c %c", &a, &b, &c);
	X(a, b, c);
	return 0;
}
void X(int a, char b, char c)
{
	int i, j, k;
	for (i = 0; i < a; i++)
	{
		for (k = i; k > 0; k--)
			printf("%c", c);
		for (j = i; j < a; j++)
			printf("%c", b);
		printf("\n");
	}


}