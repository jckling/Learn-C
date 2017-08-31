#include<stdio.h>//1-1/2+1/3-1/4+……直到最后一项的绝对值小于10-4的结果为0.693197

int main()
{
	double sum = 0;
	int i = 1;
	while (i < 10000)
	{
		if (i % 2 != 0)
			sum += 1.0 / i;
		else 
			sum -= 1.0 / i;
		i++;
	}
	printf("%lf", sum);

	return 0;
}