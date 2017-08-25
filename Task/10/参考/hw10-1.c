#include<stdio.h>
#include<string.h>
#define SIZE 20
void printstring(char *p,int n,int m);
int main()
{
    char str[SIZE];
    int m,n;
//    printf("Please input a string.\n");
//    printf("The string can store %d character:",SIZE);
    gets(str);
    do
    {
//        printf("Input n,m(n+m<=%d):",strlen(str));
        scanf("%d%d",&n,&m);
    }while(n<1||m<1||n+m>strlen(str));
    printstring(str,n,m);
    return 0;
}
void printstring(char *p,int n,int m)
{
    int i;
    p=p+n;
    for(i=0;i<m;i++)
    {
        printf("%c",*p);
        p++;
    }
}
