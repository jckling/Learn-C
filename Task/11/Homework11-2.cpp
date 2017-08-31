#include<stdio.h>
#include<string.h>

int main()
{
	char a[19], b[19];
	int i;
	scanf("%s%s%d", a, b, &i);
	if (strncmp(a, b, i) == 0)
		printf("\"%s\" is equal to \"%s\" up to %d characters\n", a, b, i);
	else if(strncmp(a, b, i) > 0)
		printf("\"%s\" is greater than \"%s\" up to %d characters\n", a, b, i);
	else if (strncmp(a, b, i) < 0)
		printf("\"%s\" is less than \"%s\" up to %d characters\n", a, b, i);

	return 0;

}