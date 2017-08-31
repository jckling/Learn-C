#include <stdio.h>
int strcompare(char *p1, char *p2);
int main()
{
	char a[80], b[80];
	scanf("%s", a);
	scanf("%s", b);
	printf("%d", strcompare(a, b));
	return 0;

}
int strcompare(char *p1, char *p2)
{
	int i = 0;
	if (p1 - p2 == 0)
		return 0;
	while (p1[i] == p2[i])
		i++;
	return p1[i] - p2[i];
}