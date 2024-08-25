#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, sum;
	while (1)
	{
		sum = 0;
		scanf("%d", &n);
		
		if (n == -1)
			break;

		for (register int i = 1; i < n; i++)
			if (n % i == 0)
				sum += i;
		
		if (n == sum)
		{
			printf("%d = 1", n);
			for (register int i = 2; i < n; i++)
				if (n % i == 0)
					printf(" + %d", i);
		}
		else
			printf("%d is NOT perfect.", n);
		printf("\n");
	}
}