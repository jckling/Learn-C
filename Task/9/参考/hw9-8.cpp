//#include <stdio.h>
// void strconnect(char *,char *);//keyi buyong mingzi 
// int main()
// {
// char str1[100], str2[100];
// scanf("%s", str1);
// scanf("%s", str2);
// strconnect(str1, str2);
// printf("%s", str1);
// }
 void strconnect(char *str1,char *str2)
 {
	 int i,len1=0,len2=0;

	 for(i=0;i<100;i++)
		 if(*(str1+i)=='\0')
		 {
			 len1=i;break;
		 }

	 for(i=0;i<100;i++)
		 if(*(str2+i)=='\0')
		 {
			 len2=i;break;
		 }


	 for(i=0;i<len2+1;i++)//把'\0'也放进去
		 *(str1+len1+i)=*(str2+i);

 return;
 }



			 