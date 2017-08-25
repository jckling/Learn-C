#include<stdio.h>
#include<math.h>
int P(int);
int Turn(int);
int main()
{
	int count = 0;
	int a, b;
	for (a = 10; a < 1000; a++)
	{
		if (P(a))
		{
			b = Turn(a);
			if (b == a)
			{
				printf("%d ", a);
				count++;
			}
		}
	}	
	printf("\n");
	printf("count=%d",count);
	return 0;
}
int Turn(int x)
{
	int y;
	if (x < 100)
		y = (x % 10)*10 + (x/10);
	else
	    y = ((x % 10) * 100) + ((x%100)/10) * 10 + (x/100);
	return y;
}

int P(int x)
{
	int i;
	int flag;
	double n;
	flag = 1;
	n = sqrt(x);
	for (i = 2; i <= n; i++)
	{
		if (x%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}