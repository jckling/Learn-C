#include<stdio.h>
int Add(int, int);
int main()
{
	int a, b;
	int result;
	scanf("%d,%d", &a, &b);
	result = Add(a, a*(b - 1));
	printf("%d", result);
	return 0;
}

int Add(int x, int y)
{
	int result;
	result = x + y;
	return result;

}