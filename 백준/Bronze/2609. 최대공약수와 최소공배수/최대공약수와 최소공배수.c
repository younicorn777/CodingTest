#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main(void)
{
	int a, b, result;
	scanf("%d%d", &a, &b);
	result = gcd(a, b);

	printf("%d\n%d", result, (a * b) / result);
}