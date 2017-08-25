#include<stdio.h>//个位数为6且能被3整除的五位数共3000个
int main()
{
	int i, counter = 0;
	for (i = 10006; i <= 99996; i += 10)
		{
		if (i % 6 == 0)
			counter++;
		}
	printf("%d", counter);

	return 0;
}