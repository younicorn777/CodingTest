#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001] = { 0 };

void SieveOfEratos(int m, int n)
{
	for (int i = 2; i <= n; i++)
		arr[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 2; i * j <= n; j++)
				arr[i * j] = 0;
		}
	}

	for (int i = m, data; i <= n; i++)
	{
		data = arr[i];
		if (data != 0)
			printf("%d\n", data);
	}
}

int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);

	SieveOfEratos(m, n);
}