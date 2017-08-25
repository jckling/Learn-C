#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main( void )
{
    char text[ 3 ][ 80 ];          /* 3 lines of text */
    char *searchPtr;               /* pointer to search character */
    char characters[ 26 ] = { 0 }; /* totals for each letter */
    int count = 0;                 /* total for current letter */
    int i;                         /* loop counter */
    int j;                         /* loop counter */
    
  //  printf( "Enter three lines of text:\n" );
    
    /* read three lines of text */
    for ( i = 0; i <= 1; i++ ) {
        gets( &text[ i ][ 0 ] );
    } /* end for */
    
    /* convert letters to lowercase */
    for ( i = 0; i <= 1; i++ ) {
        
        /* loop through each character of line */
        for ( j = 0; text[ i ][ j ] != '\0'; j++ ) {
            text[ i ][ j ] = tolower( text[ i ][ j ] );
        } /* end for */
        
    } /* end for */
    
    /* loop through alphabet */
    for ( i = 0; i <= 25; i++ ) {
        
        /* loop through 3 lines of text */
        for ( j = 0, count = 0; j <= 1; j++ ) {
            searchPtr = &text[ j ][ 0 ];
            
            /* while strchr does not return NULL */
            while ( searchPtr = strchr( searchPtr, 'a' + i ) ) {
                ++count;
                searchPtr++;
            } /* end while */
            
        } /* end for */
        
        characters[ i ] = count;
    } /* end for */
    
//    printf( "\nThe total occurrences of each character:\n" );
    
    /* display totals for each character */
    for ( i = 0; i <= 25; i++ ) {
        printf( "[%c,%d times] ", 'a' + i, characters[ i ] );
    } /* end for */
    
    return 0; /* indicate successful termination */
    
} /* end main */