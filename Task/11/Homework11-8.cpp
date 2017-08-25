#include<stdio.h>
#include<string.h>
int main()
{
	char a[100], *q[20], *p;
	int  j, k, i = 1;
	gets_s(a);
	for (j = 0; a[j] != '\0'; j++)
	{
		if (a[j] == ',' || a[j] == ';')
			a[j] = ' ';
	}
	if (a[j - 1] == '.')
		a[j - 1] = '\0';
	p = strtok(a, " ");
	q[0] = p;
	while (q[i] = strtok(NULL, " "))
		i++;
	for (j = 1; a[j] != '\0'; j++)
		printf("%c", a[j]);
	printf("%cay", a[0]);
	for (j = 1; j < i ; j++)
	{
		printf(" ");
		for(k=1; *(q[j] + k)!='\0';k++)
		printf("%c", *(q[j] + k));
		printf("%cay", *q[j]);
	}
	printf(".");
	return 0;
}