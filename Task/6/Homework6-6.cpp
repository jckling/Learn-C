#include<stdio.h>
int Per(int);
int main() 
{
	int x, y;
	int count = 0;
	for (x = 1; x < 1000; x++)
	{
		y = Per(x);
		if (x == y)
		{
			printf("%d\n", x);
			count++;
		}
	}
	printf("count=%d", count);
	return 0;
}
int Per(int x)
{
	int i,s;
	s = 0;
	for (i = 1; i < x; i++)
	{
		if (x%i == 0)
			s += i;
	}
	return s;

}