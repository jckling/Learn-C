#include <stdio.h>
#include <math.h>


int main()
{
    double a,b,c,x1,x2,m;
    
    scanf ("%lf %lf %lf",&a,&b,&c);
    
    m = b * b - 4 * a * c;
    x1 = (-b + sqrt(m)) / (2 * a);
    x2 = (-b - sqrt(m)) / (2 * a);
    if (x1<x2) {
        int t=x1;
        x1=x2;
        x2=t;
    }
    
    printf("%.2lf %.2lf\n",x1,x2);
    
    return 0;
}