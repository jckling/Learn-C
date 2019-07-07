#include<stdio.h>
#include<string.h>
int convertToInt(char num[30]) ;
int main()
{
    char num[30];
//    printf("Enter a string:\n");
    gets(num);
    printf("%d",convertToInt(num));
    return 0;
}
int convertToInt(char num[30])
{
    int i=0;
    int flag=1,n=0;
    if( num[i]=='-')
    {
        i++; flag=-1;
    }
    else
        if(num[i]=='+')
            i++;
    while(num[i]!='\0')
    {
        n=n*10+num[i]-'0';
        i++;
    }
    n=n*flag;
    return n;
}
