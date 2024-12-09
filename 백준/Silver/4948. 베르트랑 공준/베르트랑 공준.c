#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[246913] = { 0 };

void SieveOfEratos()
{
	arr[1] = 1; 
	for (int i = 2; i <= 246912; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; i * j <= 246912; j++)
				arr[i * j] = 1;
		}
	}
}

int main()
{
	int n, count;
	SieveOfEratos();

	while (1)
	{
		count = 0;
		scanf("%d", &n);

		if (n == 0)
			break;
		else
		{
			for (int i = n + 1; i <= (2 * n); i++)
			{
				if (!arr[i])
					count++;
			}
			printf("%d\n", count);
		}
	}
}