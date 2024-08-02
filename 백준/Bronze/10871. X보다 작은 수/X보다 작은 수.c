#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short n = 0, x = 0;
	short a[10000];

	scanf("%hd%hd", &n, &x);

	for (int i = 0; i < n; i++)
		scanf("%hd", &a[i]);

	for (int i = 0; i < n; i++)
		if (x > a[i])
			printf("%hd ", a[i]);
}