#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[5][16] = {'\0'};
	scanf("%s", str[0]);
	int max_size = (int)strlen(str[0]); // 가장 긴 단어의 길이

	for (int i = 1, size; i < 5; i++)
	{
		scanf("%s", str[i]);
		size = (int)strlen(str[i]);
		max_size = size > max_size ? size : max_size;
	}

	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str[j][i] == '\0')
				continue;
			else
				printf("%c", str[j][i]);
		}
	}
}