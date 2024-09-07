#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pibo(int a)
{
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else
		return (pibo(a - 1) + pibo(a - 2));
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", pibo(n));
}