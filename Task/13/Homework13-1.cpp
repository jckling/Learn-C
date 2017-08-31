#include<stdio.h>
#include<stdlib.h>

typedef struct horse
{
	int age;
	int height;
	char name[20];
	char father[20];
	char mother[20];
	struct horse *previous;
	struct horse *next;
}Horse;

int main()
{
	Horse *p1, *p2;
	char c;
	int i = 0;
	p1 = (Horse *)malloc(sizeof(Horse));
	p2 = p1;
	scanf("%c", &c);
	while (c == 'y')
	{
		scanf("%s", &(p1->name));
		scanf("%d", &(p1->age));
		scanf("%d", &(p1->height));
		scanf("%s", &(p1->father));
		scanf("%s", &(p1->mother)); getchar();
		if (i == 0)
		{
			p2->next = NULL;
			p1->previous = p2;
		}
		else
		{
			p1->previous = p2;
			p2->next = p1;
		}
		p2 = p1;                              //p2等于当前位置
		p1 = (Horse*)malloc(sizeof(Horse));   //p1开辟新位置
		i++;
		scanf("%c", &c);
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;    //倒过来输出
	for (; i > 0; i--)
	{
		printf("\n\n%s is %d years old, %d hands high,", p2->name, p2->age, p2->height);
		printf(" and has %s and %s as parents.", p2->father, p2->mother);
		p2 = p2->previous;
	}
	return 0;
}