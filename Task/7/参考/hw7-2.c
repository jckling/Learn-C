#include <stdio.h>
int main()
{
    int i;
    float a[9],max,min,ave,sum;
   // printf("请输入个评委的打分：");
    for(i=0;i<9;i++)
        scanf("%f",&a[i]);
    sum=max=min=a[0];
    for(i=1;i<9;i++)
    {
        sum+=a[i];
        if(max<a[i])
            max=a[i];
        else
            if(min>a[i])
                min=a[i];
    }
    ave=(sum-max-min)/7;
    printf("去掉最高分：%.2f，去掉最低分：%.2f，平均分为：%.2f",max,min,ave);
    return 0;
}
