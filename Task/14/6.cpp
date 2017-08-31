#include <stdio.h>
#include <string.h>

typedef struct Entry
{
	char word[15]; //单词
	char definition[50]; //单词的解释
}ENTRY;

int lookup(ENTRY dictionary[], char search[], int entries);

int main()
{
	ENTRY dictionary[100] =
	{ { "aardvark", "a burrowing African mammal" },
	{ "abyss", "a bottomless pit" },
	{ "acumen", "mentally sharp;keen" },
	{ "addle", "to become confused" },
	{ "affix", "to append;attach" },
	{ "ahoy", "a nautical call of greeting" },
	{ "ajar", "partically opened" } }; //存储了7个单词及其解释

	char word[10]; //待查找单词
	int entries = 7; //词典实际存储单词和解释的数量
	int entry;

	scanf("%14s", word);

	entry = lookup(dictionary, word, entries);

	if (entry != -1) {
		printf("%s\n", dictionary[entry].definition);
	}
	else
		printf("Sorry,the word %s is not in my dictionary", word);

	return 0;

}

int lookup(ENTRY dictionary[], char search[], int entries)
{
	int i, flag = -1;
	for (i = 0; search[i] != '\0'; i++)
	{
		if (search[i] <= 'Z')
			search[i] = search[i] - 'A' + 'a';
	}
	for (i = 0; i < 7; i++)
	{
		if (strcmp(dictionary[i].word, search) == 0)
		{
			flag = i;
			break;
		}
	}
	return flag;
}