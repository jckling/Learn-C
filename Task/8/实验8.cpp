#include<stdio.h>
int main()
{
	int N;
	int a[100][100];
	int i,j,counter,c;
	counter=c=0;

	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]<=50)
			{
				counter++;
				c++;
			}		
		}
	}
	for(i=1;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			if(a[i-1][j]<=50&&a[i+1][j]<=50&&a[i][j-1]<=50&&a[i][j+1]<=50)
				c--;
		}
	}
	printf("%d %d",counter,c);
	return 0;
}