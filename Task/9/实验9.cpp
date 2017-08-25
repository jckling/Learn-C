#include <stdio.h>
#include <string.h>

int main()
{
char str[80], *pStart, *pEnd;
int len;

gets_s(str);
len = strlen(str);
pStart = str;
pEnd = str + len - 1;
int flag;
	if(len%2!=0)
	{
		while(pStart!=pEnd)
	   {
		flag=0;
		if(*pStart==*pEnd)
		{	
		    pStart++;
		    pEnd--;
			flag=1;
		}
		else
			break;
	    }
	}
	else
	{
		while(pEnd!=(pStart+1))
        {
		flag=0;
		if(*pStart==*pEnd)
		{	
			pStart++;
		    pEnd--;
			flag=1;
		}
		else
			break;
	    }
	}
if(flag)
	printf("yes");
else
	printf("no");
return 0;
}
