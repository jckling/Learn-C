#include <stdio.h>
int main()
{
    char str[30],t[60];
    int i,j;
    gets(str);
    for(i=0,j=0;str[i]!='\0';i++)
        t[j++]=str[i];
    for(--i;i>=0;i--)
        t[j++]=str[i];
    t[j]='\0';
    puts(t);
    return 0;
}
