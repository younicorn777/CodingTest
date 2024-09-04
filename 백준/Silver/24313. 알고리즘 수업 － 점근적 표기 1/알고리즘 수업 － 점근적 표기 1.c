#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a0, a1, c, n0;
	scanf("%d%d%d%d", &a1, &a0, &c, &n0);

	if (a0 < 0 && a1 > c)   // 반례
		printf("0");
	else
	{
		if (((c - a1) * n0 - a0) >= 0)
			printf("1");
		else
			printf("0");
	}
}
