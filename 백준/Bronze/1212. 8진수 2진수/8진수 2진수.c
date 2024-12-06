#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[333335];
char rstr[1000002];

int main()
{
	int idx = 0, ridx = 0;
	scanf("%s", str);

	while (str[idx] != '\0')
	{
		if (str[idx] == '0')
		{
			rstr[ridx++] = '0';
			rstr[ridx++] = '0';
			rstr[ridx++] = '0';
		}
		else if (str[idx] == '1')
		{
			rstr[ridx++] = '0';
			rstr[ridx++] = '0';
			rstr[ridx++] = '1';
		}
		else if (str[idx] == '2')
		{
			rstr[ridx++] = '0';
			rstr[ridx++] = '1';
			rstr[ridx++] = '0';
		}
		else if (str[idx] == '3')
		{
			rstr[ridx++] = '0';
			rstr[ridx++] = '1';
			rstr[ridx++] = '1';
		}
		else if (str[idx] == '4')
		{
			rstr[ridx++] = '1';
			rstr[ridx++] = '0';
			rstr[ridx++] = '0';
		}
		else if (str[idx] == '5')
		{
			rstr[ridx++] = '1';
			rstr[ridx++] = '0';
			rstr[ridx++] = '1';
		}
		else if (str[idx] == '6')
		{
			rstr[ridx++] = '1';
			rstr[ridx++] = '1';
			rstr[ridx++] = '0';
		}
		else
		{
			rstr[ridx++] = '1';
			rstr[ridx++] = '1';
			rstr[ridx++] = '1';
		}

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