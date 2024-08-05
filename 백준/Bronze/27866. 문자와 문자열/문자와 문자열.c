#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[1000] = { '\0' };
	short a = 0;
	scanf("%s%hd", str, &a);
	printf("%c", str[a - 1]);
}