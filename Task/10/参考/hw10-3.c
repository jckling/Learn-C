//#include <stdio.h>
//
//#define ARR_SIZE 40
//
//int FindMax(int score[], long num[], int n, long *pMaxNum);
//
//int main()
//{
//    int   score[ARR_SIZE], maxScore, n, i;
//    long  num[ARR_SIZE], maxNum;
//    
////    printf("Please enter total number:");
//    scanf("%d",&n);		/*从键盘输入学生人数n*/
//    
////    printf("Please enter the number and score:\n");
//    for(i=0; i<n; i++)		/*分别以长整型和整型格式输入学生的学号和成绩*/
//    {
//        scanf("%ld%d",&num[i],&score[i]);
//    }
//    
//    maxScore = FindMax(score, num, n, &maxNum);  /*计算最高分及学生学号*/
//    
//    printf("maxScore = %d, maxNum =%ld",maxScore,maxNum);
//    
//    return 0;
//}
/* 函数功能：计算最高分及最高分学生的学号
 函数参数：整型数组score，存放学生的成绩
 长整型数组num，存放学生的学号
 长整型指针变量pMaxNum，存放求出来的最高分学生的学号
 函数返回值：最高分
 */
int FindMax(int score[], long num[], int n, long *pMaxNum)
{
    int   i;
    int   maxScore;
    
    maxScore = score[0];
    *pMaxNum = num[0];					/*假设score[0]为最高分*/
    for (i=1; i<n; i++)
    {
        if (score[i] > maxScore)
        {
            maxScore = score[i];		/*记录最高分*/
            *pMaxNum = num[i];			/*记录最高分学生的学号num[i]*/
        }
    }
    return (maxScore);					/*返回最高分maxScore*/
}

