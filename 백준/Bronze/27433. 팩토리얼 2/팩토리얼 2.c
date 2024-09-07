#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long recursion(long long a)
{
	if (a == 0) // 0! = 1
		return 1;
	else
		return (a * recursion(a - 1));
}

int main(void)
{
	long long n;
	scanf("%lld", &n);
	printf("%lld", recursion(n));
}