#include <stdio.h>
int strcompare (char *p1,char *p2);

//-------------------StartHere-----------------------

void main()
{
	char *p1, *p2, s1[20], s2[20];
	p1=s1, p2=s2;
	scanf("%s", p1);
	scanf("%s", p2);
	printf("%d", strcompare (p1,p2));
}
int strcompare (char *p1,char *p2)
{
	int result=0, i;
	for(i=0;p1[i]!='\0' && p2[i]!='\0';i++)
	{
		if(p1[i]!=p2[i])
		{
			result=p1[i]-p2[i];
			break;
		}
	}
	return result;
}