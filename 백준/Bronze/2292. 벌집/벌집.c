#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, i = 0, a = 1;
	scanf("%d", &n);
	while (n >= (a += 6 * i++) + 1);
	printf("%d", i);
}