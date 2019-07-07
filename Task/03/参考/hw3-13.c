#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double a,b,c,d,x1,x2,i,ex;
    scanf("%lf%lf%lf",&a,&b,&c);
    d = b * b - 4*a*c;
    if(a==0&&b==0)
        printf("Not an equation");
    else if (a==0&&b!=0)
    {
        x1=-c/b;
        printf("%0.2lf",x1);
    }
    else if (a!=0)
    {
        if (d>0) {
            x1=(sqrt(d)-b)/(2*a);
            x2=(-sqrt(d)-b)/(2*a);
            if(x1<x2)
            {
                ex=x1;x1=x2;x2=ex;
            }
            printf("%0.2lf %0.2lf",x1,x2);
        }
        else
        {
            x1=-b/(2*a);
            i=sqrt(-d)/(2*a);
            if(i<0)
            {
                i=-i;
            }
            printf("%0.2lf+%0.2lfi\n%0.2lf-%0.2lfi",x1,i,x1,i);
        }
    }
        return 0;
}



