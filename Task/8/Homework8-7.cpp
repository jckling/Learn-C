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
	int i, k, counter=0;
	int a[30];
	int sum=0, t;
	for (i = 0; num[i] != '\0'; i++)
	{
		a[i] = num[i];
		counter++;
	}
	if (a[0] != '+'&&a[0] != '-')
	{
		for (k = 0; k < i; k++)
		{
			t = counter - k;
			sum += (num[k] - '0')*pow(10, t - 1);
		}
	}
	else
	{
		for (k = 1; k <i; k++)
		{
			t = counter - k;
			sum += (num[k] - '0')*pow(10, t - 1);
		}
	}
	if (num[0] == '-')
		sum = -sum;
	return sum;

}