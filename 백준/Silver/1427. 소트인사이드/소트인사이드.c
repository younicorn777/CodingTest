#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[11];
	int CountArr[10] = { 0 };

	int n, size = 0;
	scanf("%d", &n);

	for (int i = n; i > 0; i /= 10)
	{
		arr[size++] = i % 10;
		CountArr[arr[size - 1]]++;
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < CountArr[i]; j++)
		{
			printf("%d", i);
		}
	}
}