#include  <stdio.h>

int main()
{
	int magic = 25;			
	int guess;				
	int counter = 0;		
	//printf("Please guess a magic number:");
	scanf("%d", &guess);
	counter ++;
	while (guess!=magic) 
	{
				if (guess > magic)
				{
					printf("Wrong!Too high!\n");
				}
				else if (guess < magic)
				{
					printf("Wrong!Too low!\n");
				}
				//printf("Please guess a magic number:");
				scanf("%d", &guess);
				counter ++;
	}
		
	printf("Right!\n");
	printf("You guess %d times\n",counter);

	printf("The game is over!\n");
}
