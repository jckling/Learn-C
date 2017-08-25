#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

struct Date
{
int day;
int month;
int year;
};

typedef struct family /* Family structure declaration */
{
struct Date dob;
char name[20];
char father[20];
char mother[20];
struct family *next; /* Pointer to next structure */
struct family *previous; /* Pointer to previous structure */
struct family *p_to_pa; /* Pointer to father structure */
struct family *p_to_ma; /* Pointer to mother structure */
}Family;

/* Function prototypes */
Family *get_person(void);
void show_people(int forwards,Family *pfirst,Family *plast);
void release_memory(Family *pfirst);

void Initparents(Family *pfirst, Family *plast); /*遍历链表中的每一个节点，并为其父亲和母亲指针域赋值。例如，节点“郭湘”的父亲名字“郭靖”与节点的“郭靖”一致，则节点“郭湘”的父亲域指针指向节点“郭靖”*/
int main(void)
{
Family *first = NULL; /* Pointer to first person */
Family *current = NULL; /* Pointer to current person */
Family *last = NULL; /* Pointer to previous person */
char more = '\0'; /* Test value for ending input */

for( ; ; )
{
// printf("\nDo you want to enter details of a%s person (Y or N)? ",
// first != NULL ? "nother" : "" );
scanf(" %c", &more);
if(tolower(more) == 'n')
break;

current = get_person();

if(first == NULL)
{
first = current; /* Set pointer to first Family */
last = current; /* Remember for next iteration */
}
else
{
last->next = current; /* Set next address for previous Family */
current->previous = last; /* Set previous address for current */
last = current; /* Remember for next iteration */
}
}

Initparents(first,last);

/* Output Family data in correct order */
printf("\nShow in a forward way.\n");
show_people(1, first, last);

release_memory(first);
first = last = NULL;

return 0;
}
Family *get_person(void)
{
	Family *p1;
	char ch;
	p1 = (Family *)malloc(sizeof(Family));
	while ((ch=getchar())!='\n'&&ch!=EOF) ;
	gets(p1->name);
	scanf("%d %d %d", &(p1->dob.day), &(p1->dob.month), &(p1->dob.year));
	getchar();
	gets(p1->father);
	gets(p1->mother);
	p1->previous = NULL;
	p1->next = NULL;
	p1->p_to_ma=NULL;
	p1->p_to_pa=NULL;
	return p1;
}
void show_people(int forwards, Family *pfirst, Family *plast)
{
	Family *p;
	if (forwards)
	{
		p=pfirst;
		while (p!=NULL)
		{
			printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n", p->name, p->dob.day, p->dob.month, p->dob.year, p->father, p->mother);
			if(p->p_to_ma!=NULL&&p->p_to_pa!=NULL)
			{
				printf("%s's birth date is %d/%d/%d",p->p_to_pa->name,p->p_to_pa->dob.day,p->p_to_pa->dob.month,p->p_to_pa->dob.year);
                printf(" and %s's birth date is %d/%d/%d.",p->p_to_ma->name,p->p_to_ma->dob.day,p->p_to_ma->dob.month,p->p_to_ma->dob.year);
			}
			else if(p->p_to_pa!=NULL)
				printf("%s's birth date is %d/%d/%d.",p->p_to_pa->name,p->p_to_pa->dob.day,p->p_to_pa->dob.month,p->p_to_pa->dob.year);
			else if(p->p_to_ma!=NULL)
				printf(" and %s's birth date is %d/%d/%d.",p->p_to_ma->name,p->p_to_ma->dob.day,p->p_to_ma->dob.month,p->p_to_ma->dob.year);
		    p = p->next;
		}
	}
	else
	{
		p=plast;
		while (p!=NULL)
		{
			printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n", p->name, p->dob.day, p->dob.month, p->dob.year, p->mother, p->father);
			p = p->previous;
		}
	}
}
void release_memory(Family *pfirst)
{
	Family *p;
	while (pfirst)
	{
		p = pfirst;
		pfirst = pfirst->next;
		free(p);
		p=NULL;
	}
}
void Initparents(Family *pfirst, Family *plast)
{
	Family *p1,*p;
	p=pfirst;
	while(p!=NULL)
	{
		p1=pfirst;
		while(p1!=NULL)
		{
			if(strcmp(p->father,p1->name)==0)
				p->p_to_pa=p1;
			if(strcmp(p->mother,p1->name)==0)
				p->p_to_ma=p1;
			p1=p1->next;
		}
		p=p->next;
	}
}