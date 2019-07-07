#include<stdio.h>

int main()
{
    int i,j,flag=0,x;	//flag为标志变量
    for(i=23;flag==0;i+=2)	//控制试探的步长和过程
    {
        for(j=1,x=i;j<=4&&x>=11;j++)	//完成出售四次的操作，j为卖的次数
        {
            if((x+1)%(j+1)==0)	//若满足整除条件则进行实际的出售操作
            {
                x-=(x+1)/(j+1);
            }
            else
            {
                x=0;
                break;	//否则停止计算过程，跳至上一层for循环
            }
        }
        if(j==5&&x==11)		//若第四次余下条则满足题意
        {
            //printf("There are %d fishes at first.\n",i);	//输出结果
            printf("%d",i);
            flag=1;		//控制退出试探过程
        }
    }
    return 0;
}

