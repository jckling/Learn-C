#include <stdio.h>

int main()
{
    double weight,height,t;
   // printf("please input your weight:");
    scanf("%lf",&weight);
    //printf("please input your height:");
    scanf("%lf",&height);
    
    t = weight/height/height;
    printf("%lf\n",t);
    
//    if (t<18) {
//        printf("lower weight");
//    }
//    if (t>=18 && t<25) {
//        printf("normal weight");
//    }
//    if (t>=25 && t<27) {
//        printf("higher weight");
//    }
//    if (t>27) {
//        printf("obesity");
//    }
    
    // second method
    
    if (t<27) {
        if(t<25){
            if (t<18) {
                printf("lower weight");
            }
            else
                printf("normal weight");
        }
        else
            printf("higher weight");
    }
    else
        printf("obesity");
    
    // third method
    
//    if (t<18)
//        printf("lower weight");
//    else if (t<25)
//        printf("normal weight");
//    else if (t<27)
//        printf("higher weight");
//    else
//        printf("obesity");
    
    
}
