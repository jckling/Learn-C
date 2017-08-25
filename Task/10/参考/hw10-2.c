#include<stdio.h>
#include<string.h>
void deletechar(char *p,char c);
#define SIZE 20
int main()
{
    char str[SIZE];
    char c;
//    printf("Please input a string.\n");
//    printf("The string can store %d character:",SIZE);
    gets_s(str);
//    printf("Please input the character you want delete:");
    scanf("%c",&c);
    deletechar(str,c);
//    printf("After deleting,The string is %s\n",str);
    puts(str);
    return 0;
}
void deletechar(char *p,char c)
{
    char *q=p;
    while(*q!='\0')
    {
        if(*q==c)
            q++;
        else
        {
            p++;
            q++;
        }
        *p=*q;
    }
    *p='\0';
}
