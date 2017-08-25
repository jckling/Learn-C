#include<stdio.h>
#define STOP '|'
int main()
{
	char c; // 当前读入的字符
	char prev; //前一个读入的字符
	long n_chars = 0; // 字符数
	int n_lines = 0; // 行数
	int n_words = 0; // 单词数
	int p_lines = 0; // 不完整的行数
	int inword = 0; // 如果当前读入的字符c在一个单词中，则inword等于1
					//printf("Enter text to be analyzed( | to terminate):\n");
	prev = '\n'; // 用于识别完整的行
	while ((c = getchar()) != STOP)
	{
		// 补充程序，统计字符数、行数、单词数
		if (c!=' '&&c!='\n'&&c!='\t')
			n_chars++;		if (c == '\n')
			n_lines++;
		if (c == ' '||c=='\n')			inword = 0;		if (inword == 0&&c!='\n')		{			inword = 1;			n_words++;		}
		prev = c;
	}
	if (prev != '\n')
		p_lines = 1;
	printf(" characters = %ld, words = %d, lines = %d, partial lines = %d\n",
		n_chars, n_words, n_lines, p_lines);
	return 0;
}