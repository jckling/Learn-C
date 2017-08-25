#include <stdio.h>
#include <string.h>

int main( void )
{
    char string1[ 20 ]; /* first string input by user */
    char string2[ 20 ]; /* second string input by user */
    int result;         /* result of using strncmp */
    int compareCount;   /* how many characters to be compared */
    
    /* get two strings from user */
//    printf( "Enter two strings: " );
    scanf( "%19s%19s", string1, string2 );
    
    /* get number of characters to compare */
//    printf( "How many characters should be compared: " );
    scanf( "%d", &compareCount );
    
    result = strncmp( string1, string2, compareCount );
    
    /* display appropriate message for result */
    if ( result > 0 ) {
        printf( "\"%s\" is greater than \"%s\" up to %d characters\n",
               string1, string2, compareCount );
    } /* end if */
    else if ( result == 0 ) {
        printf( "\"%s\" is equal to \"%s\" up to %d characters\n",
               string1, string2, compareCount );
    } /* end else if */
    else {
        printf( "\"%s\" is less than \"%s\" up to %d characters\n",
               string1, string2, compareCount );
    } /* end else */
    
    return 0; /* indicate successful termination */
    
} /* end main */

