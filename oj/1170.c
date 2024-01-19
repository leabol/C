#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void maxLenStr(char* str[], int n, int* max);

int main(void)
{
	char* pa[100];
	char a[80] = {0};
	char max = 0;
	int i = 0;
	while (fgets(a, 80, stdin), strcmp(a, "****\n") != 0)
	{
		pa[i] = (char*)malloc(sizeof(char) * (strlen(a) + 1));
		if (pa[i] == NULL)
			return 0;
		strcpy(pa[i], a);
		i++;
	}

	maxLenStr(pa, i, &max);

	puts(pa[max]);

	for (int j = 0; j < i; j++)
	{
		free(pa[j]);
	}

	return 0;
}

void maxLenStr(char* str[], int n, int* max)
{
	int longest = 0, flag = 0;

	for (int i = 0; i < n; i++)
	{
		if (strlen(str[i]) > longest)
		{
			longest = strlen(str[i]);
			flag = i;
		}
	}

	*max = flag;
}