

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
void shuffle( int deck[][ 13 ] );
void deal(int deck[][ 13 ], int hand[][ 2 ], char *suit[], char *face[] );
void pair( int hand[][ 2 ], char *suit[], char *face[] );
void threeOfKind( int hand[][ 2 ], char *suit[], char *face[] );
void fourOfKind( int hand[][ 2 ], char *suit[], char *face[] );
void straightHand( int hand[][ 2 ], char *suit[], char *face[] );
void flushHand( int hand[][ 2 ], char *suit[], char *face[] );

int main()
{
   char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
   int deck[ 4 ][ 13 ]; /* represents deck of cards */
   int hand[ 5 ][ 2 ]; /* represents hand */
   int row, column; /* loop counters */
   
   /* loop through rows of deck */
   for ( row = 0; row <= 3; row++ )
   {
      /* loop through columns of deck for current row */
      for ( column = 0; column <= 12; column++ )
      {
         deck[ row ][ column ] = 0; /* initialize slot of deck to 0 */
      } /* end inner for */
   } /* end outer for */

   srand( time( NULL ) ); /* seed random number generator */
   
   /* shuffle the deck and deal a 5-card hand */
   shuffle( deck );
   deal( deck, hand, suit, face );
   
   /* determine the hand's poker value */
   pair( hand, suit, face );
   threeOfKind( hand, suit, face );
   fourOfKind( hand, suit, face );
   straightHand( hand, suit, face );
   flushHand( hand, suit, face );
   
   return 0; /* indicate successful termination */
   
} /* end function main */

/* shuffles the deck */
void shuffle( int deck[][ 13 ] )
{
   int row; /* represents suit value of card */
   int column; /* represents face value of card */
   int card; /* loop counter */

   /* for each of the 52 cards, choose a slot of the deck randomly */
   for ( card = 1; card <= 52; card++ )
   {
      do /* choose a new random location until unoccupied slot is found */
      {
         row = rand() % 4; /* randomly select the row */
         column = rand() % 13; /* randomly select the column */
      } while( deck[ row ][ column ] != 0 ); /* end do...while */

      /* place card number in chosen slot of deck */
      deck[ row ][ column ] = card;
   } /* end for */
} /* end function shuffle */

/* deals a poker hand */
void deal( int deck[][ 13 ], int hand[][ 2 ], char *suit[], char *face[] )
{
   int r = 0; /* counter for position in the hand */
   int card, row, column; /* loop counters */

   printf( "The hand is:\n" );

   /* loop to distrubute the cards */
   for ( card = 1; card < 6; card++ )

      for ( row = 0; row <= 3; row++ )

         for ( column = 0; column <= 12; column++ )

            if ( deck[ row ][ column ] == card )
            {
               hand[ r ][ 0 ] = row;
               hand[ r ][ 1 ] = column;
               printf( "%5s of %-8s\n", face[ column ], suit[ row ] );
               ++r;
            } /* end if */

   printf( "\n" );
} /* end function deal */

/* determines if there are any pairs in the hand */
void pair( int hand[][ 2 ], char *suit[], char *face[] )
{
   /* counter that records how many cards of each rank are in the hand */
   int counter[ 13 ] = { 0 };
   
   int r, p; /* loop counters */

   /* record how many cards of each rank are in the hand */
   for ( r = 0; r < 5; r++ )
      counter[ hand[ r ][ 1 ] ]++;

   /* print result if there is a pair */
   for ( p = 0; p < 13; p++ )

      if ( counter[ p ] == 2 )
        printf( "The hand contains a pair of %ss.\n", face[ p ] );
} /* end function pair */

/* determines if there is a three of a kind in the hand */
void threeOfKind( int hand[][ 2 ], char *suit[], char *face[] )
{
   /* counter that records how many cards of each rank are in the hand */
   int counter[ 13 ] = { 0 };

   int r, t; /* loop counters */

   /* record how many cards of each rank are in the hand */
   for ( r = 0; r < 5; r++ )
      counter[ hand[ r ][ 1 ] ]++;

   /* print result if there is a three of a kind */
   for ( t = 0; t < 13; t++ )

      if ( counter[ t ] == 3 )
        printf( "The hand contains three %ss.\n", face[ t ] );
} /* end function threeOfKind */

/* determines if there is a four of a kind in the hand */
void fourOfKind( int hand[][ 2 ], char *suit[], char *face[] )
{
   /* counter that records how many cards of each rank are in the hand */
   int counter[ 13 ] = { 0 };

   int r, k; /* loop counters */

   /* record how many cards of each rank are in the hand */
   for ( r = 0; r < 5; r++ )
      counter[ hand[ r ][ 1 ] ]++;

   /* print result if there is a four of a kind */
   for ( k = 0; k < 13; k++ )

      if ( counter[ k ] == 4 )
        printf( "The hand contains four %ss.\n", face[ k ] );
} /* end function fourOfKind */

/* determines if there is a straight in the hand */
void straightHand( int hand[][ 2 ], char *suit[], char *face[] )
{
   int s[ 5 ] = { 0 }; /* array that holds a copy of hand */
   int temp; /* temporary integer */
   int r, pass, comp, j; /* loop counters */

   /* copy column locations to sort */
   for ( r = 0; r < 5; r++ )
      s[ r ] = hand[ r ][ 1 ];

   /* bubble sort column locations */
   for ( pass = 1; pass < 5; pass++ )

      for ( comp = 0; comp < 4; comp++ )

         if ( s[ comp ] > s[ comp + 1 ] )
         {
            temp = s[ comp ];
            s[ comp ] = s[ comp + 1 ];
            s[ comp + 1 ] = temp;
         } /* end if */

   /* check if sorted columns are a straight */
   if ( s[ 4 ] - 1 == s[ 3 ] && s[ 3 ] - 1 == s[ 2 ]
      && s[ 2 ] - 1 == s[ 1 ] && s[ 1 ] - 1 == s[ 0 ] )
   {
      printf( "The hand contains a straight from %s to %s.\n",
              face[ s[ 0 ] ], face[ s[ 4 ] ] );
   } /* end if */
} /* end function straightHand */

/* determines if there is a flush in the hand */
void flushHand( int hand[][ 2 ], char *suit[], char *face[] )
{
   /* counter that records how many cards of each suit are in the hand */
   int count[ 4 ] = { 0 };
   
   int r, f; /* loop counters */

   /* record how many cards of each suit are in the hand */
   for ( r = 0; r < 5; r++ )
      count[ hand[ r ][ 0 ] ]++;

   for ( f = 0; f < 4; f++ )

      if ( count[ f ] == 5 )
         printf( "The hand contains a flush of %ss.\n", suit[ f ] );
} /* end function flushHand */

