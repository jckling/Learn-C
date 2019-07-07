#include<stdio.h>
int main()
{
    int a[10],sum=0,count=0,i;
    double ave;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ave = sum/10.0;
    for (i=0; i<10; i++) {
        if (a[i]>ave) {
            count++;
        }
    }
   
    printf("%d",count);
}
