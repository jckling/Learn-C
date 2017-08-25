#include <stdio.h>
#include <stdlib.h>

/* ListNode structure definition */
struct ListNode {
	int data; /* node data */
	struct ListNode *nextPtr; /* pointer to next node */
}; /* end struct ListNode */

typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

/* function prototype */
void printList(ListNodePtr currentPtr);
void printListBackward(ListNodePtr currentPtr);
void insertItem(ListNodePtr *sPtr, int value);

int main(void)
{
	ListNodePtr startPtr = NULL; /* list pointer */
	int item; /* loop counter */
	int number;

	/* insert integers into list */
	for (item = 1; item <= 5; item++) {
		scanf("%d", &number);
		insertItem(&startPtr, number);
	} /* end for */

	printList(startPtr);
	printf("\n");
	printListBackward(startPtr);

	return 0; /* indicate successful termination */

} /* end main */
void printList(ListNodePtr currentPtr)
{
	if (currentPtr == NULL)
		printf("list is empty \n\n");
	else
	{
		while (currentPtr != NULL)
		{
			printf("%d ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
	}
}
void printListBackward(ListNodePtr currentPtr)
{
	ListNodePtr p;
	p = currentPtr;
	if (p->nextPtr != NULL)
	{
		printListBackward(p->nextPtr);
		printf("%d ", p->data);
	}
	else
	{
		printf("The list reversed is:\n");
		printf("%d ", p->data);
	}
}
void insertItem(ListNodePtr *sPtr, int value)
{
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	newPtr = (ListNodePtr)malloc(sizeof(ListNode));
	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		while (currentPtr != NULL&&value > currentPtr->data)
		{
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		if (previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}

	}
	else
		printf("%c not inserted. No memory available", value);
}