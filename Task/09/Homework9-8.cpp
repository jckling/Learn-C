#include <stdio.h>
void strconnect(char *a, char *b);
int main()
{
	char str1[100], str2[100];
	scanf("%s", str1);
	scanf("%s", str2);
	strconnect(str1, str2);
	printf("%s", str1);
}
void strconnect(char *a, char *b)
{
	int i, k;
	for (i = 0; a[i] != '\0'; i++);
	for (k = 0; b[k] != '\0'; k++)
	{
		a[i] = b[k];
		i++;
	}
	a[i] = '\0';
}