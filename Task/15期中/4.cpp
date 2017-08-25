#include<stdio.h>
void yesterday(int, int, int);
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	yesterday(a, b, c);
	return 0;
}
void yesterday(int a, int b, int c)
{
	int flag;
	flag = 0;
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		flag = 1;
	if (c == 1)
	{
		switch (b)
		{
		case 1:
			b = 12;
			a -= 1;
			c = 31;
			break;	
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			b -= 1;
			c = 30;
			break;
		case 2:
		case 4:
		case 6:
		case 9:
		case 11:
			b -= 1;
			c = 31;
			break;
		case 3:
			b -= 1;
			c = 28+flag;
			break;
				
		}
	}
	else
		c -= 1;
	printf("%d %d %d", a, b, c);
		
}