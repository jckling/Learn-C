#include<stdio.h>
#include<math.h>
void fun(double x,double y,double *c,double *q);
int main()
{
	double a,b,*c,*q;
	scanf("%lf%lf",&a,&b);
	c=&a;
	q=&b;
	fun(a,b,c,q);
	printf("%.2lf %.2lf",a,b);
	return 0;
}
void fun(double x,double y,double *c,double *q)
{
	if(x==0&&y==0)
	{	
		*c=0;
		*q=0;
	}
	else
	 {
		 *c=sqrt(x*x+y*y);
	     *q=atan(y/x);
	}
}