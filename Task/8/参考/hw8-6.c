#include <stdio.h>
#include <string.h>
int main(){
    char a[101][100]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    char xa[11][100]={"Zero","one","two","three","four","five","six","seven","eight","nine","ten"};
    int i,n;
    strcpy(a[30],"Thirty");
    strcpy(a[40],"Fourty");
    strcpy(a[50],"Fifty");
    strcpy(a[60],"Sixty");
    strcpy(a[70],"Seventy");
    strcpy(a[80],"Eighty");
    strcpy(a[90],"Ninety");
    strcpy(a[100],"One-hundred");
    scanf("%d",&n);
    if (n <= 20 || n%10==0) {
        printf("%s\n",a[n]);
    }
    else{
        printf("%s-%s\n",a[(n/10)*10],xa[n%10]);
    }
    return 0;
}
