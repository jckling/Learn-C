#include <stdio.h>
int main()
{
	int*pmax, *pmin;
	int data[10], temp, i, n;
	// printf("enter n:");
	scanf("%d", &n);
	// printf("enter %d data:",n);
	for (i = 0; i<n; i++)
		scanf("%d", &data[i]);
	printf("orgin:");
	for (i = 0; i<n; i++)
		printf("%4d", data[i]);
	printf("\n");


pmin=pmax=data;
for(i=1;i<n;i++)
{
	if(data[i]>*pmax)
		pmax=&data[i];
}
for(i=1;i<n;i++)
{
	if(data[i]<*pmin)
		pmin=&data[i];
}
printf("max=%d",*pmax);
printf("\n");
printf("min=%d",*pmin);
printf("\n");

int x;
x=data[0];
data[0]=*pmax;
*pmax=x;
if (*pmin != data[0])
{
	x = data[n - 1];
	data[n - 1] = *pmin;
	*pmin = x;
}


printf("sorted:");
for(i=0;i<n;i++)
printf("%4d",data[i]);
printf("\n");

}