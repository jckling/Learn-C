#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int N;
    scanf("%d", &N);
	while(N != 1)
	{
		if(N % 2 == 0){
			printf("%d/2=%d\n",N,N/2);
			N=N/2;
		}
		else{
			printf("%d*3+1=%d\n",N,N*3+1);
			N=N*3+1;
		}
	}
	
	printf("End");
	
	return 0;
}