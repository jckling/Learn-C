#include<stdio.h>

int main()
{
    int  i , j, k ,row;
    //printf("请输入要打印的行数:");
    scanf("%d",&row);
    for (i = 1; i <= row; i++)		/* 控制行数*/
    {
        for (j = 1; j <= row-i; j++)	/* 随行数的增加，输出递减数目的空格*/
        {
            printf(" ");
        }
        for (k = 1;k <= (2*i-1);k++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
