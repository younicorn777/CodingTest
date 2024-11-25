#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int NextUpChar(char c)
{
	int ch = c + 13;

	if (ch > 90)
		return (64 + (ch - 90));
	else
		return ch;
}

int NextLowChar(char c)
{
	int ch = c + 13;

	if (ch > 122)
		return (96 + (ch - 122));
	else
		return ch;
}

int main(void)
{
	int size;
	char str[101], data;

	scanf("%[^\n]s", str);
	size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		data = str[i];
		if (isalpha(data))
		{
			if (isupper(data))
				printf("%c", NextUpChar(data));
			else
				printf("%c", NextLowChar(data));
		}
		else
			printf("%c", data);
	}
}