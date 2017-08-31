#include <stdio.h>
#include <string.h>

void printLatinWord(char *word); 

int main(void)
{
	char s[80], *p;     
	gets_s(s);
	p = strtok(s, " .,;");
	while (p) 
	{
		printLatinWord(p);
		p = strtok(NULL, " .,;");
		if (p) 
			printf(" ");
	} 
	printf(".\n");
	return 0;
}

void printLatinWord(char *word)
{
	unsigned int i;
	for (i = 1; i < strlen(word); i++) 
		printf("%c", word[i]);
	printf("%cay", word[0]);
} 