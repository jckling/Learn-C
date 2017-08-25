//
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct Date
//{
//    int day;
//    int month;
//    int year;
//}Date;
//
//typedef struct Family                          /* Family structure declaration */
//{
//    struct Date dob;
//    char name[20];
//    char father[20];
//    char mother[20];
//    struct Family *next;                /* Pointer to next structure    */
//    struct Family *previous;           /* Pointer to previous structure */
//}Family;
//
//Family *get_person(void);       /* 获取家庭成员信息，返回链表的指针*/
//void show_people(int forwards,Family *pfirst,Family *plast); /* 显示家庭成员信息，第一个参数forwards表示正向还是反向输出，值为1时，正向输出。值为0时，反向输出。其他两个参数是链表中第一个和最后一个family对象的地址*/
//void release_memory(Family *pfirst);/*提供链表中第一个Family对象的地址，该函数就可以遍历链表中的所有元素，释放它们占用的内存。*/
//
//int main(void)
//{
//    struct Family *first = NULL;        /* Pointer to first person      */
//    struct Family *current = NULL;      /* Pointer to current person    */
//    struct Family *last = NULL;         /* Pointer to previous person   */
//    char more = '\0';                   /* Test value for ending input  */
//    
//    while(1)
//    {
////        printf("\nDo you want to enter details of a%s person (Y or N)? ",
////               first != NULL?"nother" : "");
//      
//        scanf(" %c", &more);
//        if(tolower(more) == 'n')
//            break;
//        
//        current = get_person();
//        
//        if(first == NULL)
//        {
//            first = current;                /* Set pointer to first Family  */
//        }
//        else
//        {
//            last->next = current;   /* Set next address for previous Family */
//            current->previous = last;   /* Set previous address for current */
//        }
//        last = current;/* Remember for next iteration  */
//    }
//    printf("\nShow in a forward way.\n");
//    show_people(1, first, last);
//    printf("\nShow in a reverse way.\n");
//    show_people(0, first, last);
//    release_memory(first);
//    first = last = NULL;
//
//    return 0;
//}

/*   Function to input data on Family members   */
Family *get_person(void)
{
    Family *temp;          /* Define temporary structure pointer */
    
    /* Allocate memory for a structure */
    temp = (Family*) malloc(sizeof(Family));
    
   // setbuf(stdin, NULL);
    char ch;
    while ((ch=getchar())!='\n'&&ch!=EOF) ;
    
//    printf("\nEnter the name of the person: ");
fgets(temp -> name,20,stdin);         /* Read the Family's name       */
    (temp->name)[strlen(temp->name)-1]='\0';
    
//    printf("\nEnter %s's date of birth (day month year); ", temp->name);
    scanf("%d %d %d", &temp->dob.day, &temp->dob.month, &temp->dob.year);
//   setbuf(stdin, NULL);
     while ((ch=getchar())!='\n'&&ch!=EOF) ;
//    printf("\nWho is %s's father? ", temp->name );
    fgets(temp -> father,20,stdin);        /* Get the father's name        */
     (temp->father)[strlen(temp->father)-1]='\0';
  
//    printf("\nWho is %s's mother? ", temp->name );
    fgets(temp -> mother,20,stdin);      /* Get the mother's name        */
    (temp->mother)[strlen(temp->mother)-1]='\0';
    
    temp->next = temp->previous = NULL; /* Set pointers to NULL         */
    
    return temp;                  /* Return address of Family structure */
}
void show_people(int forwards,Family *pfirst,Family *plast)
{
    for (Family *pcurrent = forwards ? pfirst:plast; pcurrent!=NULL;
         pcurrent = forwards ? pcurrent->next:pcurrent->previous) {
        printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n",
               pcurrent->name, pcurrent->dob.day, pcurrent->dob.month,
               pcurrent->dob. year, pcurrent->father,  pcurrent->mother );
    }
}

void release_memory(Family *pfirst)
{
    Family *pcurrent = pfirst;
    Family *temp = NULL;
    while (pcurrent) {
        temp = pcurrent;
        pcurrent = pcurrent->next;
        free(temp);
    }
}

    
