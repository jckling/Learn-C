#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( void )
{
    char text[ 3 ][ 80 ]; /* array to hold text entered by user */
    char search[ 20 ];    /* search string */
    char *searchPtr;      /* pointer to search string */
    int count = 0;        /* total occurrences of search string */
    int i;                /* loop counter */
    int j;                /* loop counter */
    
//    printf( "Enter three lines of text:\n" );
    
    /* read in 3 lines of text */
    for ( i = 0; i <= 2; i++ ) {
        gets( &text[ i ][ 0 ] );
    } /* end for */
    
    /* make all characters lowercase */
    for ( i = 0; i <= 2; i++ ) {
        
        /* loop through each character */
        for ( j = 0; text[ i ][ j ] != '\0'; j++ ) {
            text[ i ][ j ] = tolower( text[ i ][ j ] );
        } /* end for */
        
    } /* end for */
    
//    printf( "\nEnter a search string: " ); /* get search string */
    scanf( "%19s", search );
    
    /* loop through all three strings */
    for ( i = 0; i <= 2; i++ ) {
        
        /* set pointer to first character of string */
        searchPtr = &text[ i ][ 0 ];
        
        /* loop while strstr does not return NULL */
        while ( searchPtr = strstr( searchPtr, search ) ) {
            ++count;
            searchPtr++;
        } /* end while */
        
    } /* end for */
    
    printf( "%d\n",count );
    
    return 0; /* indicate successful termination */
    
} /* end main */