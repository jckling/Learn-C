#include<stdio.h>
int main()
{
	int i, counter = 0;
	int sum = 0;
	double avg;
	int number[10];
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &number[i]);
		sum += number[i];
	}
	avg = sum / 10;
	for (i = 0; i < 10; i++)
	{
		if (number[i] > avg)
			counter++;
	}
	printf("%d", counter);
	return 0;
}