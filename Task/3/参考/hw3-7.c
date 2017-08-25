/* Exercise 3.17 Solution */
 #include <stdio.h>

int main()
{
    double gallons; /* gallons used for current tank*/
    double miles; /* miles driven for current tank*/
     double totalGallons = 0.0; /* total gallons used */
     double totalMiles = 0.0; /* total miles driven */
     double totalAverage; /* average miles/gallon */
    
     /* get gallons used for first tank */
   //  printf( "Enter the gallons used ( -1 to end): " );
     scanf( "%lf", &gallons );
    
     /* loop until sentinel value read from user */
     while ( gallons != -1.0 ) {
         totalGallons += gallons; /* add current tank gallons to total */
        
        // printf( "Enter the miles driven: " ); /* get miles driven */
         scanf( "%lf", &miles );
         totalMiles += miles; /* add current tank miles to total */
        
         /* display miles per gallon for current tank */
       //  printf( "The Miles / Gallon for this tank was %f\n\n",miles / gallons );
      //  printf( "%f\n",miles / gallons );
         /* get next tank's gallons */
       //  printf( "Enter the gallons used ( -1 to end ): " );
         scanf( "%lf", &gallons );
         } /* end while */
    
     /* calculate average miles per gallon over all tanks */
     totalAverage = totalMiles / totalGallons;
   //  printf( "\nThe overall average Miles/Gallon was %f\n", totalAverage );
   printf( "%f\n", totalAverage );
   return 0; /* indicate successful termination */
  
  } /* end main */