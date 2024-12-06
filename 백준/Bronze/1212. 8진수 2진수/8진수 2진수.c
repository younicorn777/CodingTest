#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[333335];
char rstr[1000002];

int main()
{
	int idx = 0, ridx = 0, data;
	char convert[8][3] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	scanf("%s", str);

	while (str[idx] != '\0')
	{
		data = str[idx] - 48;

		for (int i = 0; i < 3; i++)
			rstr[ridx++] = convert[data][i];

		idx++;
	}

	if (!strcmp(rstr, "000"))
		printf("0");
	else
	{
		idx = 0;
		while (rstr[idx++] == '0');
		printf("%s", rstr + idx - 1);
	}
}