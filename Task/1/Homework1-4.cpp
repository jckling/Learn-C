#include<stdio.h>
int main()
{
	double a,b,c,v,pi;
	double num;

	    a = 9.8;
		pi=3.1415926;
		b=a/2;
		c=4.0/3;		
        v=c*b*b*b*pi/1000000;
		num=11340*v;

        printf("%lf",num);

	return 0;
}
