#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	int i;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{	
		if((i*i)%391==13)
		{
			if(i<x)
			printf("%d ",i);
		}
	}

  return 0;
}