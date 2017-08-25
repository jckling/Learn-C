#include<stdio.h>
int main()
{
	char id[18];
	int i,k,sum;
	int flag;
	flag=0;
	for(i=0;i<18;i++)
		scanf("%c",&id[i]);
	sum=7*((id[0]-'0')+(id[10]-'0'))+9*((id[1]-'0')+(id[11]-'0'))+10*((id[2]-'0')+(id[12]-'0'))+5*((id[3]-'0')+(id[13]-'0'))+8*((id[4]-'0')+(id[14]-'0'))+4*((id[5]-'0')+(id[15]-'0'))+2*((id[6]-'0')+(id[16]-'0'))+3*(id[9]-'0')+6*(id[8]-'0')+(id[7]-'0');
	k=sum%11;
	switch (k)
	{
	    case 0:
		if(id[17]=='1')
		    flag=1;
		break;
		case 1:
		if(id[17]=='0')
			flag=1;
		break;
		case 2:
		if(id[17]=='X')
			flag=1;
		break;
		case 3:
		if(id[17]=='9')
			flag=1;
		break;
		case 4:
		if(id[17]=='8')
			flag=1;
		break;
		case 5:
		if(id[17]=='7')
			flag=1;
		break;
		case 6:
		if(id[17]=='6')
			flag=1;
		break;
		case 7:
		if(id[17]=='5')
			flag=1;
		break;
		case 8:
		if(id[17]=='4')
			flag=1;
		break;
		case 9:
		if(id[17]=='3')
			flag=1;
		break;
		case 10:
		if(id[17]=='2')
			flag=1;
		break;
	}
	if(flag==1)
		printf("yes");
	else
		printf("no");
   return 0;
}