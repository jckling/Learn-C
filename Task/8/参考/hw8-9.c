#include<stdio.h>
#include<string.h>

#define M 80
#define N 6

void strInput(char [][M],int);
void strOutput(char [][M],int);
void strstrSwap(char [],char []);
void strSort(char[][M],int );

int main()
{
    char s[N][M];
    
//    printf("请输入%d个字符串：\n",N);
    strInput(s,N);
    strSort(s,N);
//    printf("排序后的结果为：\n");
    strOutput(s,N);
    
    return 0;
}
void strInput(char s[][M], int n)  //输入
{
    int i;
    for(i=0;i<n;i++)
        gets(s[i]);
}

void strOutput( char s[][M], int n)  //输出
{
    int i;
    for(i=0;i<n;i++)
        puts(s[i]);
}

void strSwap( char s1[],char s2[])   //交换
{
    char t[M];
    strcpy(t,s1);
    strcpy(s1,s2);
    strcpy(s2,t);
}

void strSort(char s[][M],int n)  //选择法排序
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(strcmp(s[j],s[min])<0)
                min=j;
        if(min!=i)
            strSwap(s[i],s[min]);
    }
}
