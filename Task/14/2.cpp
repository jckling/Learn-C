#include<stdio.h>
#include<math.h>

int main()
{
	int flag, counter;
	double i, sum;
	sum = 0;
	i = 1;
	flag = 1;
	counter = 0;
	do
	{
		sum = sum + (flag * 4 / i);
		i += 2;
		flag = flag * (-1);
		counter++;
	} while ((4 / i) >= 0.00001);
	printf("%d", counter);
	return 0;

}