#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d",&a);
    printf("%d\n",a%10);
	b=a/10;
	printf("%d\n",b%10);
	c=b/10;
	printf("%d\n",c%10);
	d=c/10;
	printf("%d\n",d%10);
	e=d/10;
	printf("%d\n",e%10);


  return 0;
}