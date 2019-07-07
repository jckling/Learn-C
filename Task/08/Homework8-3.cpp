#include<stdio.h>
int main()
{
	char str[20],t[40];
	int i, k;
	scanf("%s", str);
	for (i = 0, k = 0; str[i] != '\0'; i++)
		t[k++] = str[i];
	for (i--; i >= 0; i--)
		t[k++] = str[i];
	t[k] = '\0';
	printf("%s", t);
    return 0;
}