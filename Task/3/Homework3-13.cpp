#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c;
	double x1, x2;
	double m, n;

	scanf("%lf%lf%lf", &a, &b, &c);

	if (a == 0 && b == 0)
		printf("Not an equation");
	if (a == 0 && b != 0)
		printf("%0.2lf", -c / b);
	if (a != 0 && b != 0)
	       if(b * b - 4 * a * c >= 0)
	       { 
		     x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		     x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		     printf("%0.2lf %0.2lf", x1, x2);

	        }
		   else
		   {
			   m = -b / (2 * a);
			   n = sqrt(4 * a * c - b * b) / (2 * a);
			   if (n > 0)
				   printf("%0.2lf+%0.2lfi\n%0.2lf-%0.2lfi", m, n, m, n);
			   else
				   printf("%0.2lf+%0.2lfi\n%0.2lf-%0.2lfi", m, -n, m, -n);
		   }
	if (a != 0 && b == 0)
	{
		if (-c / a > 0)
			printf("%0.2lf", sqrt(-c / a));
		else
			printf("Not an equation");
	}

	return 0;

}