#include <stdio.h>
#include <string.h>

struct person
{   char name[20];
    int count;
}leader[3]={"li",0, "zhang",0, "wang",0};

int main()
{    
	int i, j;
	char leader_name[20];
	for (i = 1; i <= 10; i++)
	{
		scanf("%s", leader_name);
		for (j = 0; j < strlen(leader_name); j++)
		{
			if (leader_name[j] >= 'A' && leader_name[j] <= 'Z') {
				leader_name[j] = leader_name[j] + 32;
			}
		}
		for (j = 0; j < 3; j++)
		{
			if (strcmp(leader_name, leader[j].name) == 0)
				leader[j].count++;
		}
	}
    for(i=0;i<3;i++)
        printf("%s:%d\n",leader[i].name ,leader[i].count);
}