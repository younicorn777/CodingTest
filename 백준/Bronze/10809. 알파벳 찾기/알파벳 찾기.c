#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short alpha[26]; //알파벳이 처음 등장하는 위치
	char s[99];
	scanf("%s", s);

	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	for (int j = 97; j <= 122; j++)
	{
		short i = 0;
		while (s[i] != '\0')
		{
			if ((int)s[i] == j && alpha[j - 97] == -1)
				alpha[j - 97] = i;
			i++;
		}
		printf("%d ", alpha[j-97]);
	}
}