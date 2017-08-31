#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct WordCounter
{
    char *word;
    int word_count;
    struct WordCounter *pNext;                        /* Pointer to the next word counter in the list */
}WordCounter;

static char separators[] = { ' ' , ',',':' , '\"', '?' , '!' , '.'};

WordCounter *create();
void print(WordCounter *head);
void deleteone(WordCounter *head,WordCounter *pre);
//void Delete_chain(WordCounter *head);

int main()
{
	WordCounter *head;
	head = create();
	print(head);
	/*Delete_chain(head);*/

	return 0;
}

WordCounter *create()
{
	WordCounter *p1, *p2, *head;
	char ch[10000];
	char *p;
	head = NULL;
	p1 = (WordCounter *)malloc(sizeof(WordCounter));
	p2 = p1;
	gets_s(ch);
	p = strtok(ch, separators);
	p1->word = (char *)malloc(sizeof(p));
	p1->word = p;
	p1->word_count = 1;
	head = p1;
	p2->pNext = NULL;
	p2 = p1;
	p1 = (WordCounter *)malloc(sizeof(WordCounter));
	while (p = strtok(NULL, separators))
	{
		p1->word = (char *)malloc(sizeof(p));
		p1->word = p;
		p1->word_count = 1;
		p2->pNext = p1;
		p2 = p1;
		p1 = (WordCounter *)malloc(sizeof(WordCounter));
	}
	p2->pNext = NULL;
	free(p1);
	p1 = NULL;
	return head;
}

void deleteone(WordCounter *head, WordCounter *pre)
{
	WordCounter *p1, *p2;
	p1 = head;
	p2 = pre;
	if (p1->pNext == NULL)
		p2->pNext = NULL;
	else
		p2->pNext = p1->pNext;
	free(p1);
}

void print(WordCounter *head)
{
	WordCounter *p, *p1, *p2;
	p = head;
	p2 = head;
	while (p != NULL)
	{
		p1 = p->pNext;
		p2 = p;
		while (p1 != NULL)
		{
			if (strcmp(p->word, p1->word) == 0)
			{
				p->word_count++;
				deleteone(p1, p2);
				p1 = p2->pNext;
			}
			else
			{
				p2 = p1;
				p1 = p1->pNext;
			}
		}
		p = p->pNext;
	}
	p = head;
	while (p != NULL)
	{
		printf("%-20s   %5d\n", p->word, p->word_count);
		p = p->pNext;
	}
}

//void Delete_chain(WordCounter *head)
//{
//	WordCounter *p;
//	while(head!=NULL)
//	{
//		p=head;
//		free(p);
//		head=head->pNext;
//		p=NULL;
//	}
//}