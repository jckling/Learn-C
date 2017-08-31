#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char stringValue[15]; /* string input by user */
	double sum = 0.0; /* sum of all four values */
	int i; /* loop counter */

	for (i = 0; i < 4; i++)
	{
		scanf("%s", stringValue);
		sum += strtod(stringValue, NULL);
	}

	printf("The total of the values is %.2f\n", sum);

	return 0;

}