#include<stdio.h>
int main()
{
	int a,i=1;
	scanf("%d",&a);
	while (a != 25)
	{
		if (a > 25)
		{
			printf("Wrong!Too high!\n");
			scanf("%d", &a);
			i++;
		}
		else
		{
			printf("Wrong!Too low!\n");
			scanf("%d", &a);
			i++;
		}
	}
		 printf("Right!\n");
	  
	printf("You guess %d times\n",i);
	printf("The game is over!");
	return 0;


}