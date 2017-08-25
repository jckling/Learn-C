#include<stdio.h>
#define N 5
typedef struct
{
    int year,month,day;
}Date;
typedef struct
{
    char name[10];
    unsigned int id;
    Date birthday;
}Employee;
void Input(Employee *p,int n)
{
    int i;
    for( i=0;i<n;i++,p++)
    {
//        printf("输入第%d个员工的姓名、工号、生日（年月日）：",i+1);
        scanf("%s%d%d%d%d",p->name , &p->id,&p->birthday.year, &p->birthday.month,&p->birthday.day );
    }
}
void Search( Employee *p,int n,Date d)
{
    int flag=0,count = 0;
    Employee *q = p+n;
    while( p< q)
    {

        if( p->birthday.month == d.month && p->birthday.day == d.day)
        {
            count++;
            if (count ==1) {
                printf("%d月%d日过生日的有：\n",d.month ,d.day );
                printf("       姓名    工号    生日(年   月   日)\n");
            }

            printf("%8s%10d%14d%4d%4d\n",p->name ,p->id,p->birthday.year ,p->birthday .month ,p->birthday .day );
            p++;
            flag = 1;
          
            continue;
        }
        p++;        
    }
    if (flag==0) {
        printf("Not Found\n");
    }
}
int main()
{
    Employee a[N];
    Date d;
    int i=0,n;
//    printf("请输入员工总人数：");
    scanf("%d",&n);   
    Input(a,n); 
//        printf("请输入待查的生日（月、日）：");
        scanf("%d%d",&d.month,&d.day);
                Search(a,n,d);
    return 0;
}
