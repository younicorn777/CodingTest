#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str1[15], str2[8], str3[15], str4[8];

	scanf("%s%s%s%s", str1, str2, str3, str4);
	strcat(str1, str2);
	strcat(str3, str4);

	printf("%lld", atoll(str1) + atoll(str3));
}