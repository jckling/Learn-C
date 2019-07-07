#include <stdio.h>
#include <string.h>

char key[5][5];

void set55table(char *keystr)
{
	char letter[2][26]={0};
	int i;
	for(i=0;i<26;i++)
	{
		letter[0][i]='a'+i;
	}
	letter[1]['j'-'a']=1;

	int j,k=0,restk=0;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			while(1)
			{
				if(keystr[k]>='a' && keystr[k] <='z') 
				{  
					if(letter[1][keystr[k]-'a']==0)
					{	key[i][j]=keystr[k];
						letter[1][keystr[k]-'a']=1;
						k++;
						break;
					}
					else
					{   k++;}
				}
				else if (keystr[k]==0)
				{
					if(letter[1][restk]==0)
					{key[i][j]='a'+restk;
					letter[1][restk]=1;
					restk++;
					break;
					}
					else restk++;

				} else
				{ k++;
				}
			}
		}
	
}

void setplaintext(char *p, char *newp)
{
	int i=0,j=0,k;
	while(1)
	{
		if(p[i]!=0 && p[i+1]!=0 && p[i]!=p[i+1])
		{	newp[j++]=p[i++];
			 newp[j++]=p[i++];
		}
		else if (p[i]!=0 && p[i+1]!=0 && p[i]==p[i+1])
		{
			newp[j]=p[i];
			i++;j++;
			newp[j]='x';
			j++;
		} else if (p[i]!=0 && p[i+1]==0)
		{
			newp[j]=p[i];
			j++;
			newp[j]='x';
			j++;
			break;
		} else if (p[i]==0)
		{
			break;
		}
	}
	p[j]=0;
	
}


int getpos(char a, int *pi,int *pj)
{

	int i,j;

        for(i=0;i<5;i++)
        {       
                for(j=0;j<5;j++)
                {
			if(key[i][j]==a)
			{
				*pi=i; *pj=j; return 1;
			}
			
                }
        }
	return 0;
}


void encode(char *newp,char *cipher)
{
	int sizen,i;
	sizen=strlen(newp);
	if(sizen%2!=0 ) 
	{
		   printf("error in encode");
                        return;

	}	
	
	for(i=0;i<sizen;i+=2)
	{
		int i1,i2,j1,j2;
		if(getpos(newp[i],&i1,&j1) && getpos(newp[i+1],&i2,&j2))
		{
			if(i1==i2)
			{
				cipher[i]=key[i1][(j1+1)%5];
				cipher[i+1]=key[i1][(j2+1)%5];
			} else if(j1==j2)
			{
                                cipher[i]=key[(i1+1)%5][j1];
                                cipher[i+1]=key[(i2+1)%5][j2];
                        } else
			{
				cipher[i]=key[i1][j2];
                                cipher[i+1]=key[i2][j1];

			}
			
		}
		else
		{
			printf("error in encode");
			return;
		}
	
	}
	cipher[i]=0;
	
	
}


main()
{

	//char p[]="communiistooooo";
//	char p[]="hidethegold";
//	char p[]="wearediscoveredsaveyourselfx";
//
	
	char p[1000]="helloworld";
	char password[1000]="helloworld";
	scanf("%s",password);	
	scanf("%s",p);	
//
	char newp[1000]={0},cipher[1000]={0};	
	int i,j,k;
	setplaintext(p,newp);
//	printf("%s\n",newp);

	//set55table("crazy dog");
//	set55table("playfirexm");
	set55table(password);

	for(i=0;i<5;i++)
	{	//printf("\n");
		for(j=0;j<5;j++)
		{
			//printf("%2c",key[i][j]);
		}
	}
	
	encode(newp,cipher);
	
	printf("%s",cipher);
	
}
