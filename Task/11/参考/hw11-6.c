#include <stdio.h>
#include <string.h>

int main( void )
{
    char text[ 4 ][ 80 ]; /* text entered by user */
    char *tokenPtr;       /* pointer to current token */
    int i;                /* loop counter */
    int counter = 0;      /* token counter */
    
//    printf( "Enter 4 lines of text: \n" );
    
    /* read 4 lines of text */
    for ( i = 0; i <= 3; i++ ) {
        gets( &text[ i ][ 0 ] );
    } /* end for */
    
    /* loop through 4 lines of text */
    for ( i = 0; i <= 3; i++ ) {
        
        /* get first token */
        tokenPtr = strtok( &text[ i ][ 0 ], " \n" );
        
        /* while tokenPtr does not equal NULL */
        while ( tokenPtr ) {
            ++counter;
            tokenPtr = strtok( NULL, " \n" ); /* get next token */
        } /* end while */
        
    } /* end for */
    
    printf( "%d\n", counter );
    
    return 0; /* indicate successful termination */
    
} /* end main */