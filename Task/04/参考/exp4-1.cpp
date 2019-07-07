#include  <stdio.h>

int main()
{
	int magic = 25;
	int guess;
	int counter = 0;

	do
	{
		//printf("Please guess a magic number:");
		scanf("%d", &guess);
		counter++;

		if (guess > magic)
		{
			printf("Wrong!Too high!\n");
		}
		else if (guess < magic)
		{
			printf("Wrong!Too low!\n");
		}

	} while (guess != magic && (counter<5));

	if (guess == magic)
		printf("Right!\n");
	printf("You guess %d times\n", counter);

	printf("The game is over!\n");
}
