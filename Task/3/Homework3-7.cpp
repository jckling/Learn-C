#include<stdio.h>
int main()
{
	double x,y,total = 0, sum = 0;	
	scanf("%lf", &x);
    while (x != -1)
	{
		scanf("%lf", &y);
		sum += y;
		total += x;
		scanf("%lf", &x);		
	}
    printf("%lf",sum / total);
	return 0;
}