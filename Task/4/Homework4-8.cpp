#include<stdio.h>
int main()
{
	int a,max;
    scanf("%d", &a);
	max = a;
	do{
		if (a % 2 == 0)
			a /= 2;
		else
			a = 3 * a + 1;
		if (max < a)
			max = a;
	}while (a != 1);
	printf("%d", max);
	return 0;
}