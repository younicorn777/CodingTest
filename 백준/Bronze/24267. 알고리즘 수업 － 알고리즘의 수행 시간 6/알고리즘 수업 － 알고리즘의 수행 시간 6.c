#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	long long n;
	scanf("%lld", &n);
	printf("%lld\n3", n * (n - 1) * (n - 2) / 6);
}