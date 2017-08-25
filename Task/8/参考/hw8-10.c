#include<stdio.h>
void Mygets(char s[],int n)
{
    int i=0;
    do
    {
        s[i]=getchar();
    }while(s[i]!='\n' && ++i <n);
    s[i]='\0';
    
}
int Count(char s[])
{
    int count=0,//记录单词个数
    word=0,           //单词标记，-空格，-单词
    i=0;
    while(s[i]!='\0')          //当s[i]不是'\0'时
    {
        if(s[i++]==' ')           //若s[i]是空格
            word=0;                 //设置空格标志
        else if(word==0)      //如果单词标志为空格，说明此字符是单词的首字符
        {
            word=1;             //设置单词标志，避免同一单词重复计数
            count++;
        }
    }
    return count;
}
int main()
{
    char s[1024];
//    printf("请输入一行字符串（<1024个字符）：");
    Mygets(s,1023);
//    printf("字符串中单词的个数为%d。\n",Count(s));
    printf("%d",Count(s));
    return 0;
}
