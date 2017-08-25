#include<stdio.h>
double After(double);
double Total(double);
int main()
{
	double x;
  scanf("%lf",&x);
  do
  {  
	  printf("After expenses:$%.2lf\n", After(x));
	  printf("Total raised:$%.2lf\n",Total(x));
	  scanf("%lf",&x);
  }while(x>0);
  return 0;
}


	
double After(double x)
{
	x=0.83*x;
	return x;
}

double Total(double x)
{
	static double s;
	s += After(x);
	return s;

}