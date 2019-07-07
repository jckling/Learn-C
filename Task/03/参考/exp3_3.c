#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>			/*将函数time所需要的头文件time.h包含到程序中*/
int main()
{
	int magic;				/*计算机"想"的数*/
	int guess;				/*人猜的数*/

	srand(time(NULL));		/*用标准库函数srand()为函数rand()设置随机数种子*/
	magic = rand() % 100 + 1;
	printf("Please guess a magic number:");
	scanf("%d", &guess);

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
	printf("The number is:%d\n", magic);
}
