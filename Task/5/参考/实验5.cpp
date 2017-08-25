
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* enumeration constants represent game status */
enum Status { CONTINUE, WON, LOST };

int rollDice(void); /* function prototype */
enum Status craps(void); /* function prototype */
void chatter(void); /* function prototype */

int main()
{
	enum Status result;     /* result of current game */
	int wager = 0;          /* wager for current game */
	int bankBalance = 1000; /* current bank balance */

	srand(time(NULL)); /* seed random number generator */

					   /* display current balance and prompt for wager */
	printf("You have $%d in the bank.\n", bankBalance);
	printf("Place your wager: ");
	scanf("%d", &wager);

	/* loop while not valid wager */
	while (wager <= 0 || wager > 1000) {
		printf("Please bet a valid amount.\n");
		scanf("%d", &wager);
	} /* end while */

	result = craps(); /* play game of craps */

					  /* if player lost current game */
	if (result == LOST) {

		/* decrease balance by wager and display new balance */
		bankBalance -= wager;
		printf("Your new bank balance is $%d\n", bankBalance);

		/* if balance is 0 */
		if (bankBalance == 0) {
			printf("Sorry. You are Busted! Thank You For Playing.\n");
		} /* end if */

	} /* end if */
	else { /* player won game */

		   /* increase balance by wager and display new balance */
		bankBalance += wager;
		printf("Your new bank balance is $%d\n", bankBalance);
	} /* end else */

	return 0; /* indicate successful termination */

} /* end main */

  /* roll dice, calculate sum and display results */
int rollDice(void)
{
	int die1;    /* first die value */
	int die2;    /* second die value */
	int workSum; /* sum of dice */

	die1 = 1 + rand() % 6; /* pick random die1 value */
	die2 = 1 + rand() % 6; /* pick random die2 value */
	workSum = die1 + die2; /* sum die1 and die2 */

						   /* display results of this roll */
	printf("Player rolled %d + %d = %d\n", die1, die2, workSum);

	return workSum; /* return sum of dice */

} /* end function rollDice */

  /* craps plays one game of craps, returns result of game */
enum Status craps(void)
{
	enum Status gameStatus; /* can contain CONTINUE, WON or LOST */
	int sum;                /* current roll of dice */
	int myPoint;            /* point value */

	sum = rollDice(); /* first roll of dice */

					  /* determine game status and point based on sum of dice */
	switch (sum) {

		/* win on first roll */
	case 7:
	case 11:
		gameStatus = WON;
		chatter();
		break; /* exit switch */

			   /* lose on first roll */
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		chatter();
		break; /* exit switch */

			   /* remember point */
	default:
		gameStatus = CONTINUE;
		myPoint = sum;
		printf("Point is %d\n", myPoint);
		chatter();
		break; /* exit switch */
	} /* end switch */

	  /* while game not complete */
	while (gameStatus == CONTINUE) {
		chatter();
		sum = rollDice(); /* roll dice again */

						  /* determine game status */
		if (sum == myPoint) {
			gameStatus = WON; /* win by making point */
		} /* end if */
		else {

			if (sum == 7) {
				gameStatus = LOST; /* lose by rolling 7 */
			} /* end if */

		} /* end else */

	} /* end while */

	  /* display won or lost message and return status */
	if (gameStatus == WON) {
		printf("Player wins\n");
		return WON;
	} /* end if */
	else {
		printf("Player loses\n");
		return LOST;
	} /* end else */

} /* end function craps */

  /* chatter displays messages at random to create "chatter" */
void chatter(void)
{
	int select; /* random number */

	select = 1 + rand() % 6;

	/* choose message at random */
	switch (select) {

	case 1:
		printf("Oh, you're going for broke, huh?\n");
		break; /* exit switch */

	case 2:
		printf("Aw cmon, take a chance!\n");
		break; /* exit switch */

	case 3:
		printf("Hey, I think this guy is going to break the bank!!\n");
		break; /* exit switch */

	case 4:
		printf("You're up big. Now's the time to cash in your chips!\n");
		break; /* exit switch */

	case 5:
		printf("Way too lucky! Those dice have to be loaded!\n");
		break; /* exit switch */

	case 6:
		printf("Bet it all! Bet it all!\n");
		break; /* exit switch */

	default:
		break; /* exit switch */
	} /* end switch */

} /* end function chatter */

