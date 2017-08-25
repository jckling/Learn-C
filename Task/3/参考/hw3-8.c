#include<stdio.h>

int main()
{
    int i=1;
    double s=0;
    for(i=1;i<=20;i++)
    {
        if(i%2)
            s=s+1.0*i/(i+(i+1)+(i+2));
        else
            s=s-1.0*i/(i+(i+1)+(i+2));
    }
    //printf("s=1/(1+2+3)-2/(2+3+4)+3/(3+4+5)-4/(4+5+6)+……的前项之和为%lf\n",s);
    printf("%lf\n",s);
    return 0;
}
