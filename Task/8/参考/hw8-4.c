
#include  <stdio.h>
#define ARR_SIZE 30

int	ReadScore(long num[], float score[]);
int	GetFail(long num[], float score[], int n);
float GetAver(float score[], int n);
int	GetAboveAver(long num[], float score[], int n);
void GetDetail(float score[], int n);

int main()
{
    int n, fail, aboveAver;
    float score[ARR_SIZE];
    long num[ARR_SIZE];
    
//    printf("Please enter num and score until score<0:\n");
    n = ReadScore(num, score);
    printf("Total students %d\n\n",n);
    
    fail = GetFail(num, score, n);
    printf("Fail students %d\n\n",fail);
    
    aboveAver = GetAboveAver(num, score, n);
    printf("Above aver students %d\n\n",aboveAver);
    
    GetDetail(score, n);
}
/*函数功能：从键盘输入一个班学生某门课的成绩及其学号
 当输入成绩为负值时，输入结束
 函数参数：长整型数组num，存放学生学号
 实型数组score，存放学生成绩
 函数返回值：学生总数
 */
int ReadScore(long num[], float score[])
{
    int i = 0;
    
    scanf("%ld%f",&num[i],&score[i]);
    
    while (score[i] >= 0 && i<ARR_SIZE)
    {
        i++;
        scanf("%ld%f",&num[i],&score[i]);
    }
    return i;
}

/*函数功能：统计不及格人数并打印不及格学生名单
 函数参数：长整型数组num，存放学生学号
 实型数组score，存放学生成绩
 整型变量n，存放学生总数
 函数返回值：不及格人数
 */
int GetFail(long num[], float score[], int n)
{
    int  i, count;
    
    printf("Fail:\nnumber -- score\n");
    count = 0;
    for (i=0; i<n; i++)
    {
        if (score[i] < 60)
        {
            printf("%4ld%12.2f\n",num[i], score[i]);
            count++;
        }
    }
    return count;
}

/*函数功能：计算全班平均分
 函数参数：实型数组score，存放学生成绩
 整型变量n，存放学生总数
 函数返回值：平均分
 */
float GetAver(float score[], int n)
{
    int    i;
    float  sum = 0;
    
    for (i=0; i<n; i++)
    {
        sum = sum + score[i];
    }
    return sum/n;
}

/*函数功能：统计成绩在全班平均分及平均分之上的学生人数并打印其学生名单
 函数参数：长整型数组num，存放学生学号
 实型数组score，存放学生成绩
 整型变量n，存放学生总数
 函数返回值：成绩在全班平均分及平均分之上的学生人数
 */
int GetAboveAver(long num[], float score[], int n)
{
    int   i, count;
    float aver;
    
    aver = GetAver(score, n);
    printf("aver = %.2f\n", aver);
    
    printf("Above aver:\nnumber -- score\n");
    count = 0;
    for (i=0; i<n; i++)
    {
        if (score[i] >= aver)
        {
            printf("%4ld%10.2f\n",num[i], score[i]);
            count++;
        }
    }
    return count;
}

/*函数功能：统计各分数段的学生人数及所占的百分比
 函数参数：实型数组score，存放学生成绩
 整型变量n，存放学生总数
 函数返回值：无
 */
void GetDetail(float score[], int n)
{
    int  i, j, stu[6];
    for (i=0; i<6; i++)
    {
        stu[i]=0;
    }
    for (i=0; i<n; i++)
    {
        if (score[i] < 60)
        {
            j = 0;
        }
        else
        {
            j = ((int)score[i] - 50) / 10;
        }
        stu[j]++;
    }
    printf("score   number   percent\n");
    for (i=0; i<6; i++)
    {
        if (i == 0)
        {
            printf("<60%8d%12.2f\n",stu[i],(float)stu[i]/(float)n*100);
        }
        else if (i == 5)
        {
            printf("%d%8d%12.2f\n",(i+5)*10,stu[i],(float)stu[i]/(float)n*100);
        }
        else
        {
            printf("%d--%d%5d%12.2f\n",(i+5)*10,(i+5)*10+9,stu[i],(float)stu[i]/(float)n*100);
        }
    }
}
