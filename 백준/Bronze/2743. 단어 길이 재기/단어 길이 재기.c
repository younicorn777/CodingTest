#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char str[100] = { '\0' };
	short count = 0; // 문자열의 길이

	scanf("%s", str);
	while (str[count++] != '\0');
	printf("%hd", count - 1);
}