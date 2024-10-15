#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, num;
	scanf("%d", &n);
	int CountArr[10001] = { 0 };

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		CountArr[num]++;
	}

	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < CountArr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}