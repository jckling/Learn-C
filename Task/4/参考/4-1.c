#include<stdio.h>

int main()
{
    int age;
    printf("please input the age:");
    scanf("%d",&age);
    switch(age)
    {
        case 2:
        case 3:
            printf("age:%d,enter Lower class\n",age);
            break;
        case 4:
            printf("age:%d,enter Middle class\n",age);
            break;
        case 5:
        case 6:
            printf("age:%d,enter Higher class\n",age);
            break;
        default:
            printf("Your age is wrong!\n");
    }
    return 0;
}

