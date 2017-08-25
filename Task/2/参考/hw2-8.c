#include <stdio.h>
// function main begins program execution
int main()
{
    double x;
    scanf("%lf",&x);
  
    int y = x + 0.5;
    int z = (x + 0.05) * 10;
   // int w = (x + 0.005) * 100;
    printf("%d\n",x);
    printf("%d\n%g\n%g\n",y,z/10.,(int)((x + 0.005) * 100)/100.);
    
    return 0; // indicate that program ended successfully
    
} // end function main