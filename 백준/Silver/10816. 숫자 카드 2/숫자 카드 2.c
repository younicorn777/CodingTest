#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BASE 10000000

int arr[20000001] = { 0 };

int main()
{
	int n, m, data;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		arr[data + BASE]++;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &data);
		printf("%d ", arr[data + BASE]);
	}
}