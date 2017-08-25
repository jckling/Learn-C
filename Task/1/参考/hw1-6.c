#include <stdio.h>

int main()
{
    double density = 11340;  //球密度
    double exDiameter,inDiameter ;  //球的外径，内径
    double volume,weight;   //分别为球体积，球重量
    
    scanf("%lf",&exDiameter);
    scanf("%lf",&inDiameter);
    
    double temp =  (exDiameter/2) * (exDiameter/2) * (exDiameter/2)-(inDiameter/2) * (inDiameter/2) * (inDiameter/2);
    volume = 4.0/3 * 3.1415926 * temp;
    
    weight = volume / 1000000 * density;
    
    printf("%lf",weight);  //小数的输出格式为％lf。lf means long float.
    
    return 0;
}
