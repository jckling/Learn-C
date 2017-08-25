#include<stdio.h>
int main()
{
	double a,b,c,d,v,pi;
	double num;

	    scanf("%lf", &a);
	    scanf("%lf", &b);

		pi=3.1415926;
		c=4.0/3;		
        v=c*(a/2*a/2*a/2-b/2*b/2*b/2)*pi/1000000;
		num=11340*v;

        printf("%lf",num);

	return 0;
}
