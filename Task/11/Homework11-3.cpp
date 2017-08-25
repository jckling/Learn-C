#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[50], *q[10];
	int i, j;
	i = 1;
	gets_s(a);
	q[0] = strtok(a, " ");
	while (q[i] = strtok(NULL, " "))
		i++;
	for (j = i - 1; j >= 0; j--)
		printf("%s ", q[j]);
	return 0;
}