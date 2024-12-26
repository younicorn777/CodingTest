#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int find(int num)
{
	if (num == 1) return 0;
	if (num == 2 || num == 3) return 1;

	int min, result;

	int* Table = (int*)malloc(sizeof(int) * (num + 1));
	Table[2] = 1;
	Table[3] = 1;

	for (int i = 4; i <= num; i++)
	{
		min = Table[i - 1]; 

		if (i % 2 == 0)
			min = (Table[i / 2] > min) ? min : Table[i / 2];

		if (i % 3 == 0)
			min = (Table[i / 3] > min) ? min : Table[i / 3];

		Table[i] = min + 1;
	}

	result = Table[num];
	free(Table);
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", find(n));
}