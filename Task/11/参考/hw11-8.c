#include <stdio.h>
#include <string.h>

void printLatinWord( char *word ); /* function prototype */

int main( void )
{
    char sentence[ 80 ]; /* sentence input by user */
    char *tokenPtr;      /* pointer to current token */
    
//    printf( "Enter a sentence:\n" );
    gets( sentence );
//    printf( "\nThe sentence in pig Latin is:\n" );
    
    /* call function strtok to alter the sentence */
    tokenPtr = strtok( sentence, " .,;" );
    
    /* if tokenPtr does not equal NULL */
    while ( tokenPtr ) {
        
        /* pass the token to printLatinWord and get next token */
        printLatinWord( tokenPtr );
        tokenPtr = strtok( NULL, " .,;" );
        
        /* if tokenPtr not NULL, print space */
        if ( tokenPtr ) {
            printf( " " );
        } /* end if */
        
    } /* end while */
    
    printf( ".\n" );
    
    return 0; /* indicates successful termination */
    
} /* end main */
/* print out the English word in pig Latin form */
void printLatinWord( char *word )
{
    unsigned int i; /* loop counter */
    
    /* loop through the word */
    for ( i = 1; i < strlen( word ); i++ ) {
        printf( "%c", word[ i ] );
    } /* end for */
    
    printf( "%c%s", word[ 0 ], "ay" );
} /* end function printLatinWord */