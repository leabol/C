#include <stdio.h>
#include <stdlib.h>
#include "run.h"

int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	int* p = malloc(sizeof(int) * (n * m));
	if (p == NULL)
		return 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", (p + n * i + j));
		}
	}

	start();

	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (i == 0 || i == m - 1)
		{
			for (int j = 0; j < n; j++)
			{
				sum += *(p + n * i + j);
			}
		}
		else
			sum += ( * (p + n * i) + *(p + n * i + m));
	}

	printf("%d", sum);

	free(p);

	end();
}