#include  <stdio.h>

int main()
{
    int magic = 25;
    int guess;
    
   
    //printf("Please guess a magic number:");
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
