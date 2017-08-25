#include<stdio.h>
#include<stdlib.h>
int main()
{		double *values = NULL;   		double *temp = NULL;       		double sum = 0.0;         		int capacity = 0;       		int increment = 6;         		int count = 0, i = 0;		char answer;		do		{			if (count == capacity)    			{				capacity += increment; 				temp = (double*)realloc(values, (capacity) * sizeof(double)); 				values = temp;				temp = NULL;         			}			for (i = count; i < capacity; i++)			{				scanf("%lf", &values[i]);				count++;			}			scanf(" %c", &answer);		} while (answer == 'y');		for (i = 0; i < capacity; i++)		{			printf("%10.1lf", values[i]);			sum += values[i];			if ((i + 1) % 6 == 0)			{				printf("%10.1lf\n", sum / 6);				sum = 0;			}		}		free(values);    
		return 0;
}