#include <stdio.h>
#include <string.h>
void table(char * inkey,char * key,int  * alphabet){
	int i,top=0,now=0;
	for (i=0;i<strlen(inkey);i++){
		if (!alphabet[inkey[i]-'a']) {
			key[top++]=inkey[i];
			alphabet[inkey[i]-'a']=1;
		}
	}
	now=0;
	for (;top<=25;top++){
		for (;now<=25;now++){
			if (!alphabet[now]) {
				key[top]='a'+now;
				alphabet[now]=1;
				break;
			}
		}
	}
	key[26]='\0';
}
int pos(char * str,char val) {
	return strchr(str,val)-str;
}
void divefied(char * input, char * res){
	int i=0;
	char s[3]="";
	for (i=0;i<strlen(input);i++){
		if (input[i]=='j') input[i]='i';
	}
	i=0;
	while (i<strlen(input)) {
		//printf("aa");
		if (input[i]==input[i+1]||i==strlen(input)-1) {
			s[0]=input[i];
			s[1]='x';
			s[2]='\0';
			//printf("%s",s);
			strcat(res,s);
			i++;
		} else {
			s[0]=input[i];
			s[1]=input[i+1];
			s[2]='\0';
			//printf("%s",s);
			strcat(res,s);
			i+=2;
		}
	}
	//printf("%s\n",res);
}
int hengjia(int a){
	return (a/5)+(a+1)%5;
}
int shujia(int a){
	if (a<20)
		return a+5;
	else
		return a-20;
}
void xiejia(int a,int b,int * ra,int * rb){
	int xa=a%5,ya=a/5*5;
	int xb=b%5,yb=b/5*5;
	*ra=ya+xb;
	*rb=yb+xa;
}
int main(void){
	char input[1000]; //receive the input
	char res[1000]="";
	char inkey[30]="",key[30]=""; //the actual key table
	int alphabet[30]={0}; //Yes or NO the alphabet has been chosen
	alphabet['j'-'a']=1;
	//fgets(key,30,stdin);
	//key[strlen(key)-1]='\0';
	//fgets(input,1000,stdin);
	//input[strlen(input)-1]='\0';
	scanf("%s",inkey);
	scanf("%s",input);
	table(inkey,key,alphabet);
	//printf("%s\n",key);
	divefied(input,res);
	//printf("%s\n",res);
	int i;
	for (i=0;i<strlen(res);i+=2) {
		int pos1=pos(key,res[i]),pos2=pos(key,res[i+1]);
		//printf("%d %d\n",pos1,pos2);
		if (pos1/5==pos2/5) {
			res[i]=key[hengjia(pos1)];
			res[i+1]=key[hengjia(pos2)];
		} else if (pos1%5==pos2%5) {
			res[i]=key[shujia(pos1)];
			res[i+1]=key[shujia(pos2)];
		} else {
			int ra,rb;
			xiejia(pos1,pos2,&ra,&rb);
			//printf("%d %d %d %d %d %d\n",i,i+1,pos1,pos2,ra,rb);
			res[i]=key[ra];
			res[i+1]=key[rb];
		}
	}
	//printf("%s\n",key);
	printf("%s\n",res);
	return 0;
}
