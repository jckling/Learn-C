#include<stdio.h>
int main()
{
	int counter = 1, number, largest;
	scanf("%d\n", &number);
	largest = number;
	while (counter < 10)
	{
		if (largest < number)
		largest = number;
		counter++;
		scanf("%d", &number);
	}
	printf("Largest is %d", largest);
	return 0;
}