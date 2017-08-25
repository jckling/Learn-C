#include<stdio.h>
int main()
{
	int fahr,celsius;
	int upper,lower,step;

	upper=300;
    lower=0;
	step=20;
    fahr=lower;

	while(fahr<=upper)
	{
		celsius=5*(fahr-32)/9;
		printf("%d\t%d\n",fahr,celsius);
		fahr=fahr+step;
	}
	return 0;
}