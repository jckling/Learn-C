#include<stdio.h>
#include<stdlib.h>

typedef struct horse
{
	int age;
	int height;
	char name[20];
	char father[20];
	char mother[20];
	struct horse *next;
}Horse;

int main()
{
	Horse *head, *p1, *p2, *p;
	char c;
	int i = 0;
	p1 = (Horse *)malloc(sizeof(Horse));
	p2 = p1;
	head = NULL;
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
			head = p1;
			p2->next = NULL;
		}
		else
			p2->next = p1;
		p2 = p1;
		p1 = (Horse*)malloc(sizeof(Horse));
		i++;
		scanf("%c", &c);
	}
	p2->next = NULL;
	free(p1);
	p1 = NULL;
	p = head;
	for (; i > 0; i--)
	{
		printf("\n\n%s is %d years old, %d hands high,", p->name, p->age, p->height);
		printf(" and has %s and %s as parents.", p->father, p->mother);
		p = p->next;
	}
	return 0;
}