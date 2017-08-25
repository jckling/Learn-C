#include  <stdio.h>

int main()
{
	int magic = 25;			
	int guess;				
	int counter = 0;		
	do
	{
		scanf("%d", &guess);
		counter++;
		if (guess > magic)
			printf("Wrong!Too high!\n");
		else if (guess < magic)
			printf("Wrong!Too low!\n");
		else if (guess == magic)
		{
			printf("Right!\n");
			break;
		}
	}while(counter < 5);
	printf("You guess %d times\n",counter);
	printf("The game is over!\n");
	return 0;
}
