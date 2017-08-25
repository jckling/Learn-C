#include<stdio.h>
int main()
{
    double a,b,c;
	double S,p;

	scanf("%lf %lf %lf", &a, &b, &c);
	p=(a+b+c)/2;
	S=p*(p-a)*(p-b)*(p-c);
	printf("%.2lf",S);

	return 0;
}