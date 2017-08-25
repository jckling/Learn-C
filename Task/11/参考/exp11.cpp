#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	/* initialize 4 arrays of char pointers */
	char *article[] = { "the", "a", "one", "some", "any" };
	char *noun[] = { "boy", "girl", "dog", "town", "car" };
	char *verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
	char *preposition[] = { "to", "from", "over", "under", "on" };
	char sentence[100] = ""; /* completed sentence */
	int i; /* loop counter */

		   /* create 5 sentences */
	for (i = 1; i <= 5; i++) {

		/* randomly choose pieces of sentence */
		strcat(sentence, article[rand() % 5]);
		strcat(sentence, " ");

		strcat(sentence, noun[rand() % 5]);
		strcat(sentence, " ");

		strcat(sentence, verb[rand() % 5]);
		strcat(sentence, " ");

		strcat(sentence, preposition[rand() % 5]);
		strcat(sentence, " ");

		strcat(sentence, article[rand() % 5]);
		strcat(sentence, " ");

		strcat(sentence, noun[rand() % 5]);

		/* capitalize first letter and print sentence */
		putchar(toupper(sentence[0]));
		printf("%s.\n", &sentence[1]);
		sentence[0] = '\0';
	} /* end for */

	return 0; /* indicate successful termination */

} 