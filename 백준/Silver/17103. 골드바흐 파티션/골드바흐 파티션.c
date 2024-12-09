#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001] = { 0 };

void SieveOfEratos()
{
	for (int i = 2; i <= 1000000; i++)
		arr[i] = i;

	for (int i = 2; i <= 1000000; i++)
	{
		if (arr[i])
		{
			for (int j = 2; i * j <= 1000000; j++)
				arr[i * j] = 0; 
		}
	}
}

int main()
{
	SieveOfEratos();
	
	int t, data1, data2;
	scanf("%d", &t);

	for (int i = 0, n, count; i < t; i++)
	{
		count = 0;
		scanf("%d", &n);

		for (int i = 2; i <= (n / 2); i++)
		{
			data1 = arr[i];
			data2 = arr[n - data1];

			if (data1 != 0 && data2 != 0)
				count++;
		}
		printf("%d\n", count);
	}
}