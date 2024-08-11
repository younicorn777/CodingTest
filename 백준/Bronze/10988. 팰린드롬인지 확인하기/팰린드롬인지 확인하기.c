#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[101] = { '\0' };
	scanf("%s", str);

	int i, j;
	for (i = 0, j = (int) strlen(str) - 1; i < j; i++, j--) {
		if (str[i] != str[j])
			break;
	}

	(i >= j) ? printf("1"): printf("0");
}