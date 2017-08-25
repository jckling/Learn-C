/* Exercise 8.15 solution */
#include <stdio.h>
#include <string.h>

void reverseTokens( char *sentence ); /* function prototype */

int main( void )
{
    char text[ 80 ]; /* line of text from user */
    
//    printf( "Enter a line of text:\n" );
    gets( text );
    
    reverseTokens( text ); /* call to function reverseTokens */
    
    return 0; /* indicate successful termination */
    
} /* end main */

/* function to reverse the individual tokens */
void reverseTokens( char *sentence )
{
    char *pointers[ 50 ]; /* array to store entire sentence */
    char *temp;           /* pointer to each token */
    int count = 0;        /* token counter */
    int i;                /* loop counter */
    
    /* function strtok takes first word of sentence */
    temp = strtok( sentence, " " );
    
    /* while temp does not equal NULL */
    while ( temp ) {
        
        /* add the word into the array and get next token */
        pointers[ count++ ] = temp;
        temp = strtok( NULL, " " );
    } /* end while */
    
//printf( "The tokens in reverse order are:\n" );
    
    /* loop through the array backward */
    for ( i = count - 1; i >= 0; i-- ) {
        printf( "%s ", pointers[ i ] );
    } /* end for */
    
    printf( "\n" );
} /* end function reverseTokens */



/*************************************************************************
 * (C) Copyright 1992-2007 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
