//
//#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//struct Date
//{
//    int day;
//    int month;
//    int year;
//};
//
//typedef struct family                          /* Family structure declaration  */
//{
//    struct Date dob;
//    char name[20];
//    char father[20];
//    char mother[20];
//    struct family *next;                 /* Pointer to next structure     */
//    struct family *previous;             /* Pointer to previous structure */
//    struct family *p_to_pa;              /* Pointer to father structure   */
//    struct family *p_to_ma;              /* Pointer to mother structure   */
//}Family;
//
///* Function prototypes */
//Family *get_person(void);
//void show_people(int forwards,Family *pfirst,Family *plast);
//void release_memory(Family *pfirst);
//
//void Initparents(Family *pfirst, Family *plast); /*遍历链表中的每一个节点，并为其父亲和母亲指针域赋值。例如，节点“郭湘”的父亲名字“郭靖”与节点的“郭靖”一致，则节点“郭湘”的父亲域指针指向节点“郭靖”*/





//int main(void)
//{
//    Family *first = NULL;        /* Pointer to first person      */
//    Family *current = NULL;      /* Pointer to current person    */
//    Family *last = NULL;         /* Pointer to previous person   */
//    char more = '\0';                   /* Test value for ending input  */
//    
//    for( ; ; )
//    {
////       printf("\nDo you want to enter details of a%s person (Y or N)? ",
////               first != NULL ? "nother" : "" );
//        scanf(" %c", &more);
//        if(tolower(more) == 'n')
//            break;
//        
//        current = get_person();
//        
//        if(first == NULL)
//        {
//            first = current;                /* Set pointer to first Family  */
//            last = current;                 /* Remember for next iteration  */
//        }
//        else
//        {
//            last->next = current;   /* Set next address for previous Family */
//            current->previous = last;   /* Set previous address for current */
//            last = current;             /* Remember for next iteration      */
//        }
//    }
//    
//    Initparents(first,last);
//   
//    /* Output Family data in correct order */
//    printf("\nShow in a forward way.\n");
//    show_people(1, first, last);
//    
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
void Initparents(Family *pfirst, Family *plast)
{
    //函数声明
    bool set_ancestry(Family *pmember1, Family *pmember2);
    bool related (Family *pmember1, Family *pmember2);
    
    Family* pcurrent = NULL;
    pcurrent = pfirst;
    
    while(pcurrent->next != NULL) /* Check for relation for each person in */
    {                            /* the list up to second to last         */
        int parents = 0;        /* Declare parent count local to this block */
        plast = pcurrent->next;   /* Get the pointer to the next              */
        
        while(plast != NULL)     /* This loop tests current person           */
        {                       /* against all the remainder in the list    */
            if(related(pcurrent, plast))           /* Found a parent ?          */
                if(++parents == 2)     /* Yes, update count and check it        */
                    break;               /* Exit inner loop if both parents found */
            
            plast = plast->next;       /* Get the address of the next           */
        }
        pcurrent = pcurrent->next;   /* Next in the list to check             */
    }
    
}
bool set_ancestry(Family *pmember1, Family *pmember2)
{
    if(strcmp(pmember1->father, pmember2->name) == 0)
    {
        pmember1->p_to_pa = pmember2;
        return true;
    }
    
    if( strcmp(pmember1->mother, pmember2->name) == 0)
    {
        pmember1->p_to_ma = pmember2;
        return true;
    }
    else
        return false;
}

/* Fill in pointers for mother or father relationships */
bool related (Family *pmember1, Family *pmember2)
{
    return set_ancestry(pmember1, pmember2) ||
    set_ancestry(pmember2, pmember1);
}
void show_people(int forwards,Family *pfirst,Family *plast)
{
    for (Family *pcurrent = forwards ? pfirst:plast; pcurrent!=NULL;
         pcurrent = forwards ? pcurrent->next:pcurrent->previous) {
        printf("\n%s was born %d/%d/%d, and has %s and %s as parents.\n",
               pcurrent->name, pcurrent->dob.day, pcurrent->dob.month,
               pcurrent->dob. year, pcurrent->father,  pcurrent->mother );
        if(pcurrent->p_to_pa != NULL )
            printf("%s's birth date is %d/%d/%d",
                   pcurrent->father, pcurrent->p_to_pa->dob.day,
                   pcurrent->p_to_pa->dob.month,
                   pcurrent->p_to_pa->dob.year);
        if(pcurrent->p_to_ma != NULL)
            printf(" and %s's birth date is %d/%d/%d.",
                   pcurrent->mother, pcurrent->p_to_ma->dob.day,
                   pcurrent->p_to_ma->dob.month,
                   pcurrent->p_to_ma->dob.year);
        if (pcurrent->p_to_pa != NULL && pcurrent->p_to_ma == NULL) {
            printf(".");
        }
        
        if(pcurrent->p_to_pa != NULL ||pcurrent->p_to_ma != NULL)
            printf("\n");
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

