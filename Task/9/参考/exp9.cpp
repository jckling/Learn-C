#include <stdio.h>
#include <string.h>

int main()
{
    char str[80], *pStart, *pEnd;
    int len;
    
//    printf("Input string: ");
    gets(str);
    len = strlen(str);
    pStart = str;
    pEnd = str + len - 1;
while ((*pStart == *pEnd) && (pStart < pEnd))
{
	pStart++;
	pEnd--;
}
if (pStart < pEnd)
{
	printf("no\n");
}
else
{
	printf("yes\n");
}
    return 0;
}