#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100] = { '\0' };

	scanf("%s", str);
	printf("%zu", strlen(str));
}