#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int t, i, n;
	int Table[11];
	Table[1] = 1;
	Table[2] = 2;
	Table[3] = 4;

	for (int i = 4; i < 11; i++)
		Table[i] = Table[i - 1] + Table[i - 2] + Table[i - 3];

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%d\n", Table[n]);
	}
}