#include <stdio.h>

int main()
{
    double density = 11340;  //球密度
    double diameter = 9.8;  //球的直径
    
    double volume,weight;   //分别为球体积，球重量
    
    volume = (4.0/3) * 3.1415926 * (diameter/2) * (diameter/2) * (diameter/2);  //此处不能写作4/3，因为在C语言中，两个整数相除，结果仍为整数，4/3的结果为1.所以将4改为4.0或者将3改为3.0
    weight = volume / 1000000 * density;
    
    printf("%lf",weight);  //小数的输出格式为％lf。lf means long float.
    
    return 0;
}
