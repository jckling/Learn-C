#include<stdio.h>
#include<string.h>
#include<math.h>
int convertToInt(char num[30]);
int main()
{
	char num[30];
	gets_s(num);
	printf("%d", convertToInt(num));
	return 0;
}
int convertToInt(char num[30])
{
	int i, j, k;
	int temp, sum = 0;
	if (num[0] == '+' || num[0] == '-')
	{
		for (i = 1; num[i] != '\0'; i++);
		for (j = i - 1, k = 0; j > 0; j--, k++)
		{
			temp = (num[j] - '0')*(pow(10, k));
			sum += temp;
		}
	}
	else
	{
		for (i = 0; num[i] != '\0'; i++);
		for (j = i - 1, k = 0; j >= 0; j--, k++)
		{
			temp = (num[j] - '0')*(pow(10, k));
			sum += temp;
		}
		return sum;
	}
	if (num[0] == '+')
		return sum;
	else
		return -sum;
}