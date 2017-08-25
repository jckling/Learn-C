#include<stdio.h>
#include<string.h>
void deletechar(char *p, char c);
#define SIZE 20
int main()
{
	char str[SIZE];
	char c;
	// printf("Please input a string.\n");
	// printf("The string can store %d character:",SIZE);
	gets_s(str);
	// printf("Please input the character you want delete:");
	scanf("%c", &c);
	deletechar(str, c);
	// printf("After deleting,The string is %s\n",str);
	puts(str);
	return 0;
}
void deletechar(char *p, char c)
{
	char *a = p, *b = p;
	int i, j;
	j = 0;
	for (i = 0; a[i] != '\0'; i++)
	{
		if (a[i] != c)
		{
			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	strcpy(p, b);
}
