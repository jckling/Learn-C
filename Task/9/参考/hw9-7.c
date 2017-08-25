#include <stdio.h>
#include <string.h>
#include <ctype.h>

int sd(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    else {
        return 0;
    }
}

int findLongWord(char *str) {
   int i,len=0, length=0, place=0, flag = 1, point;
   for(i=0; i<=strlen(str); ++i) {
       if (sd(str[i])) {
           if (flag) {
               point = i;
               flag = 0;
           }
           else {
               ++len;
           }
       }
       else {
           flag = 1;
           if (len >= length) {
               length = len;
               len = 0;
               place = point;
           }
       }
   }
   return place;
}

int main(void) {
    char str[100];
    int i;
    gets(str);
    printf("word=");

    for (i=findLongWord(str); sd(str[i]); ++i) {
        printf("%c", str[i]);
    }

    return 0;
}