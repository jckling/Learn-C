#include <stdio.h>
struct student
{
    char name[10];
    int no;
    float score[2];
};
void maxscore(struct student *pst,int n);
void average(struct student *pst,int n);
void sort(struct student *pst,int n);

int main()
{
    struct student st[45];
    int i,n;
   // printf("请输入学生人数：");
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
//        printf("\n请输入第%d个学生的姓名：",i+1);
        gets(st[i].name);
//        printf("请输入第%d个学生的学号：",i+1);
        scanf("%d",&st[i].no);
//        printf("请输入第%d个学生的第一门课程成绩：",i+1);
        scanf("%f",&st[i].score[0]);
//        printf("请输入第%d个学生的第二门课程成绩：",i+1);
        scanf("%f",&st[i].score[1]);
        getchar();
    }
//    printf("\nName\t\tNo\tScore1\tScore2\n");
//    for(i=0;i<n;i++)
//        printf("%s\t\t%ld\t%5.1f\t%5.1f\n",st[i].name,st[i].no,st[i].score[0],st[i].score[1]);
//    printf("\n");
//    printf("最高分为：\n");
    maxscore(st,n);
    printf("Below average:\n");
    average(st,n);
//    printf("对编号的课程从高分到低分排序：\n");
//    sort(st,n);
}

void maxscore(struct student *pst,int n)
{
    int i,j,maxno,maxi;
    float maxs;
    maxs=pst[0].score[0];
    maxi=maxno=0;
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
            if(pst[i].score[j]>maxs)
            {
                maxs=pst[i].score[j];
                maxi=i;
                maxno=j;
            }
    printf("MaxSore=%5.1f,Name is %s,No=%d,Score.No=%d\n",
           pst[maxi].score[maxno],pst[maxi].name,pst[maxi].no,maxno+1);
}

void average(struct student *pst,int n)
{
    float ave1=0,ave2=0;
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        ave1+=pst[i].score[0];
        ave2+=pst[i].score[1];
    }
    ave1=ave1/n;
    ave2=ave2/n;
//    printf("ave1=%5.1f,ave2=%5.1f\n",ave1,ave2);
//    printf("两门课程均低于平均分的学生姓名和学号：\n");
//    printf("Name\t\tNo\n");
	for (i = 0; i < n; i++)
	{
		if (pst[i].score[0] < ave1 &&pst[i].score[1] < ave2)
		{
			printf("%s\t\t%d\n", pst[i].name, pst[i].no);
			flag = 1;
		}
	}
    if(flag!=1)
        printf("Not Found\n");
    
}
//void sort(struct student *pst,int n)
//{
//    struct student t;
//    int i,j;
//    for(i=0;i<n-1;i++)
//        for(j=i+1;j<n;j++)
//            if(pst[i].score[0]<pst[j].score[0])
//            {
//                t=pst[i];
//                pst[i]=pst[j];
//                pst[j]=t;
//            }
//    printf("\nName\t\tNo\tScore1\tScore2\n");
//    for(i=0;i<n;i++)
//        printf("%s\t\t%d\t%5.1f\t%5.1f\n",pst[i].name,pst[i].no,pst[i].score[0],pst[i].score[1]);
//}
