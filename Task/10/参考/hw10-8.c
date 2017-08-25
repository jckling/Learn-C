#include <stdio.h>
#include <stdlib.h>
#define CAP_INCR 10
//#include <stdbool.h>
int main(void)
{
    unsigned long *primes = NULL;       /* Pointer to primes storage area    */
    unsigned long limit = 0;            /* Integer to be tested              */
    int found = 0;                 /* Indicates when we find a prime    */
    int total = 0;                   /* Number of primes required         */
    int count = 0;                   /* Number of primes found            */
//    printf("Enter the upper limit for primes you want to find: ");
    scanf("%d", &limit);    
    int capacity = 10;
    primes = (unsigned long *)calloc(capacity,sizeof(unsigned long));
    if(!primes)
    {
        printf("\nNot enough memory. \n");
        return 1;
    }        
    /* We know the first three primes     */
    /* so let's give the program a start. */
    *primes = 2UL;                      /* First prime                   */
    *(primes+1) = 3UL;                  /* Second prime                  */
    *(primes+2) = 5UL;                  /* Third prime                   */
    count = 3;                         /* Number of primes stored       */  
    unsigned long trial = *(primes + 2) + 2;
    unsigned long *ptemp = NULL;  
    /* Find all the primes required */
    while(trial<= limit)
    {       
        /* Try dividing by each of the primes we have       */
        /* If any divide exactly - the number is not prime  */
        for(int i = 0 ; i < count ; i++)
            if(!(found = (trial % *(primes+i))))
                break;                        /* Exit if no remainder          */        
        if(found)                        /* we got one - if found is true */
        {
            if( count == capacity)
            {
                capacity +=CAP_INCR;
                ptemp = (unsigned long *)realloc(primes,capacity * sizeof(unsigned long));
                if( !ptemp)
                {
                    printf("\nNot enough memory. \n");
                    free(primes);
                    primes = NULL;
                    return 2;
                }
                primes = ptemp;
            }
            
            *(primes+count++) = trial;     /* Store it and increment count  */
        }
        trial += 2;
    }
    
    /* Display primes 5-up */
    for(int i = 0 ; i < count ; i ++)
    {
        if(!(i%5U ||i==0))
            printf("\n");                   /* Newline after every 5         */
        printf ("%8lu", *(primes+i));
    }
    printf("\n");                       /* Newline for any stragglers    */   
    free(primes);                       /* Release the memory         */
    return 0;
}

