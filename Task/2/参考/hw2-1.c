#include <stdio.h>
// function main begins program execution
int main()
{
    int plainText;            // stores the number of original text
    int cipherText;          // stores the number of encrypted text
    
    //printf("Enter number to encrypt: ");
    scanf("%d",&plainText);
    
    cipherText = plainText * 7 + 5;
    
    //printf("Encrypted number: %d\n",cipherText);
    printf("%d\n",cipherText);
    
    return 0; // indicate that program ended successfully
    
} // end function main