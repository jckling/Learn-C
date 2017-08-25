#include<stdio.h>
double charge(double);
int main()
{
	
	int k = 1;
	double H, C;
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("%5s%15s%15s\n", "Car", "Hours", "Charge");
	H = a + b + c;
	C = charge(a) + charge(b) + charge(c);
	printf("%5d%15.1f%15.2f\n",k,a,charge(a));
	printf("%5d%15.1f%15.2f\n", k+1, b, charge(b));
	printf("%5d%15.1f%15.2f\n", k+2, c, charge(c));
	printf("%5s%15.1f%15.2f","TOTAL",H,C);

	return 0;
}

double charge(double x)
{
	if (x <= 3)
		x = 2;
	else if (x > 3 && x < 19)
	{
		if (x > int(x))
			x = 2 + int(x - 2) * 0.5;
		else
			x = 2 + int(x - 3)*0.5;
	}
	else
		x = 10;
	return x;

}