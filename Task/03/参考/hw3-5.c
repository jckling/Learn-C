#include<stdio.h>

int main()
{
    int i=1000;
    int count=0;			/*count:统计满足条件的五位数的个数*/
    while(i<=9999)
    {
        if(!((i*10+6)%3))	/*判断所选的数能否被整除*/
            count++;		/*若满足条件则计数*/
        i++;
    }
    printf("%d\n",count);
    
    return 0;
}
