#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b;

	while (scanf("%hd%hd", &a, &b) != EOF)
		printf("%hd\n", a + b);
}