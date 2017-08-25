#include<stdio.h>
int main()
{
	struct student
	{
		char name[20];
		char sex;
		int age;
		double score;
	}student[45];
	int n, i, max=0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(student[i].name);	
		scanf("%c", &student[i].sex);
		getchar();
		scanf("%d", &student[i].age);
		getchar();
		scanf("%lf", &student[i].score);
		getchar();
	}
	printf("\nName\t\tSex\tAge\tScore\n");
	for (i = 0; i < n-1; i++)
	{
		if (student[max].score < student[i + 1].score)
			max = i + 1;
	}
	printf("%s\t\t%c\t%d\t%5.1f\n", student[max].name,student[max].sex,student[max].age,student[max].score);
	return 0;
}