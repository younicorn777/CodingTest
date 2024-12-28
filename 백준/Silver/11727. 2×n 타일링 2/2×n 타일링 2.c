#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int find (int n)
{
	if (n == 1) return 1;
	if (n == 2) return 3;

	int result;
	int* Table = (int*)malloc(sizeof(int) * (n + 1));
	
	Table[1] = 1;
	Table[2] = 3;

	for (int i = 3; i <= n; i++)
		Table[i] = (Table[i - 1] + 2 * Table[i - 2]) % 10007;

	result = Table[n];
	free(Table);
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", find(n));
}