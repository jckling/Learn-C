#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);

	if (a==2||a==3)
		printf("age:%d,enter Lower class",a);
	else if (a==4)
	         printf("age:%d,enter Middle class",a);
    else
	         printf("age:%d,enter Higher class",a);

	return 0;


}