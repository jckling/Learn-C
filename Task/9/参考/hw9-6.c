//#include<stdio.h>
//#include<string.h>
//int numbers(char *p);
//#define SIZE 20
//int main()
//{
//    char str[SIZE];
//    int num;
////    printf("Please input a string.\n");
////    printf("The string can store %d character:",SIZE);
//    gets(str);
//    num=numbers(str);
//    printf("There are %d numbers in \"%s\"",num,str);
//    return 0;
//}
int numbers(char *p)
{
    int i=0;
    while(*p!='\0')
    {
        if(*p>='0'&&*p<='9')
            i++; 
        p++;
    }
    return i;
}
