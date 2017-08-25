/* Exercise 7.16 Solution */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function prototypes */
void shuffle( int workDeck[][ 13 ] );
void deal( int workDeck[][ 13 ], char *workFace[], char *workSuit[] );

int main()
{ 
   int card = 1;        /* card counter */
   int row;             /* loop counter */
   int column;          /* loop counter */
   int deck[ 4 ][ 13 ]; /* array of cards */

   /* define arrays of card suits and faces */
   char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades"};
   char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", 
      "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

   srand( time( NULL ) );
   
   /* initialize deck */
   for ( row = 0; row <= 3; row++ ) {

      for ( column = 0; column <= 12; column++ ) {
         deck[ row ][ column ] = card++;
      } /* end for */

   } /* end for */
         
   shuffle( deck );
   deal( deck, face, suit );

   return 0; /* indicate successful termination */

} /* end main */

/* introduce another way to shuffle */
void shuffle( int workDeck[][ 13 ] )
{ 
   int temp;       /* temporary holder */
   int row;        /* loop counter */
   int column;     /* loop counter */
   int randRow;    /* random suit */
   int randColumn; /* random face */
   
   /* run through the loop and touch every element once */
   for ( row = 0; row <= 3; row++ ) {

      for ( column = 0; column <= 12; column++ ) { 

         /* generate a random card */
         randRow = rand() % 4;
         randColumn = rand() % 13;

         /* swap random card with current card */
         temp = workDeck[ row ][ column ];
         workDeck[ row ][ column ] = workDeck[ randRow ][ randColumn ];
         workDeck[ randRow ][ randColumn ] = temp;
      } /* end for */

   } /* end for */

} /* end function shuffle */

/* deal the cards */
void deal( int workDeck2[][ 13 ], char *workFace[], char *workSuit[] )
{ 
   int card;   /* card counter */
   int row;    /* loop counter */
   int column; /* loop counter */
   
   /* loop through and print the cards */
   for ( card = 1; card <= 52; card++ ) {

      /* loop through rows */
      for ( row = 0; row <= 3; row++ ) {

         /* loop through columns */
         for ( column = 0; column <= 12; column++ ) {

            /* if current card equals card, then deal */
            if ( workDeck2[ row ][ column ] == card ) { 
               printf( "%5s of %-8s", workFace[ column ], workSuit[ row ] );
               card % 2 == 0 ? putchar( '\n' ) : putchar( '\t' );
               break; /* break loop */
            } /* end if */

         } /* end for */

      } /* end for */

   } /* end for */

} /* end function deal */



 /*************************************************************************
 * (C) Copyright 1992-2006by Deitel & Associates, Inc. and               *
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
