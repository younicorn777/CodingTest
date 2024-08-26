#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b;
	scanf("%hd%hd", &a, &b);
	printf("%d", a * b);
}