#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	switch(a)
	{
	case 2:
	case 3:
			printf("age:%d,enter Lower class",a);
			break;
	case 4:
			printf("age:%d,enter Middle class",a);
			break;
	case 5:
	case 6:
			printf("age:%d,enter Higher class",a);
			break;
	}
	return 0;
}
			

