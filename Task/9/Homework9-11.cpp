#include<stdio.h>
int main()
{
	int size[12] = { 52,53,54,55,56,57,58,59,60,61,62,63 }, bank[12] = { 164,166,169,172,175,178,181,184,188,191,194,197 };
	int real;
	int i, flag;
	double wide;
	scanf("%lf", &wide);
	real = int(wide * 8);
	for (i = 0; i < 12; i++)
	{
		flag = 0;
		if (real == bank[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		if (real < 164 && real >= 163)
			real = 164;
		for (i = 0; i < 12; i++)
		{
			if (real<(bank[i + 1] - 1) && real>bank[i]&&real<bank[i+1])
			{
				real = bank[i];
				break;
			}
			else if (real<bank[i+1]&&real > bank[i] && real >= (bank[i + 1] - 1))
			{
				real = bank[i + 1];
				break;
			}
		}
	}
	if(real>197)
		printf("You, in technical parlance, are a fathead. No hat for you, I'm afraid.\n");
	else if(real<163)
		printf("You are the proverbial pinhead. No hat for you I'm afraid.\n");
	else
	{
		for (i = 0; i < 12; i++)
		{
			if (real == bank[i])
			{
				printf("%d", size[i] / 8);
				if (size[i] % 8 == 2)
					printf(" 1/4");
				else if (size[i] % 8 == 4)
					printf(" 1/2");
				else if (size[i] % 8 == 6)
					printf(" 3/4");
				else if (size[i] % 8 == 0);
				else
					printf(" %d/8", size[i] % 8);
				break;
			}
		}
	}
	return 0;
}