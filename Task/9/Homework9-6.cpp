#include<stdio.h>
#include<string.h>

#define SIZE 20

int numbers(char *p);

int main()
{
	char str[SIZE];
	int num;
	// printf("Please input a string.\n");
	// printf("The string can store %d character:",SIZE);
	gets_s(str);
	num = numbers(str);
	printf("There are %d numbers in \"%s\"", num, str);
	return 0;
}

int numbers(char *p)
{
	int i, count = 0;
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] >= '0' && p[i] <= '9')
			count++;
	}
	return count;
}