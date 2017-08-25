#include<stdio.h>
#include<math.h>
int main()
{
	double S1,S2,x1,x2;
	double a,b,c,x,y;

	scanf("%lf %lf %lf", &a, &b, &c);

	        x=b*b-4*a*c;
			a = 2 * a;
			y = sqrt(x);
			S1 = -b + y;
			S1 = S1 / a;
			S2 = -b - y;
			S2 = S2 / a;
		  printf("%.2f %.2f", S1, S2);

	return 0;
}