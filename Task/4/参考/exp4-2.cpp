#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>

int main()
{
	int magic;				/*计算机"想"的数*/
	int guess;				/*人猜的数*/
	int counter;			/*记录人猜的次数*/
	char reply;				/*用户输入的回答*/

	srand(time(NULL));
	do
	{
		magic = rand() % 100 + 1;
		counter = 0;
		do
		{
			printf("Please guess a magic number:");
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
			else
			{
				printf("Right!\n");
			}
		} while ((guess != magic) && (counter<6));
		/*猜不对且未超过10次时继续猜*/
		printf("counter = %d\n", counter);
		printf("The magic number is %d\n", magic);
		printf("Do you want to continue(Y/N or y/n)?");
		scanf("%1s", &reply);
		//		scanf(" %c",&reply);  //注意这里%c前面要有一个空格，以忽略上次输入数字时的回车

	} while ((reply == 'Y') || (reply == 'y'));

	printf("The game is over!\n");
}
