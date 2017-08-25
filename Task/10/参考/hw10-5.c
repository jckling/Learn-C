#include <stdio.h>
int main()
{
    int n;
    static char *monthName[]={"Illegal month", "January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    
//    printf("Input month number:");
    scanf("%d", &n);								  /*输入月份*/
    if ((n <= 12) && (n >= 1))
        printf("%s\n", monthName[n]);  /*输出相应月份*/
    else
        printf("%s\n", monthName[0]);				  /*输出错误*/
}
