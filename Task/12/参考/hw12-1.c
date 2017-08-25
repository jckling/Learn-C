#include <stdio.h>
struct student
{
    char name[10];
    char sex;
    int age;
    float score;
};
int main()
{
    struct student st[45];
    int i,n,maxi;
    float maxs;
//    printf("请输入学生人数：");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
//        printf("\n请输入第%d个学生的姓名：",i+1);
        gets(st[i].name);
//        printf("请输入第%d个学生的性别（F or M）：",i+1);
        scanf(" %c",&st[i].sex);
//        printf("请输入第%d个学生的年龄：",i+1);
        scanf("%d",&st[i].age);
//        printf("请输入第%d个学生的成绩：",i+1);
        scanf("%f",&st[i].score);
        getchar();
    }
    maxs=st[0].score;
    maxi=0;
    for(i=1;i<n;i++)
        if(st[i].score>maxs)
        {
            maxs=st[i].score;
            maxi=i;
        }
    printf("\nName\t\tSex\tAge\tScore\n");
    printf("%s\t\t%c\t%d\t%5.1f\n",st[maxi].name,st[maxi].sex,st[maxi].age,st[maxi].score );
}
