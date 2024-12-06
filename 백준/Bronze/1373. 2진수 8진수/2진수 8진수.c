#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[1000001];
short rstr[400000] = { 0 };

int main()
{
	int ridx = 0, result;
	scanf("%s", str);
	int sidx = strlen(str) - 1;

	while (sidx >= 0)
	{
		result = 0;

		for (int j = 1; j <= 4 && sidx >= 0; j *= 2, sidx--)
			result += ((str[sidx] - 48) * j);

		rstr[ridx++] = result;
	}

	for (int i = (ridx - 1); i >= 0; i--)
		printf("%hd", rstr[i]);
}