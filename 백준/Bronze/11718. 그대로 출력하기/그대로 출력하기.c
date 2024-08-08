#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101] = { '\0' };
	while (scanf("%[^\n]s", str) != EOF)
	{
		printf("%s\n", str);
		getchar();
	}
}