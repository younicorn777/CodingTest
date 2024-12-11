#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	long long n, i, j, count = 0;
	scanf("%lld", &n);
	
	for (i = 1, j = 1; i <= n; count++, j++, i = j * j);
	
	printf("%lld", count);
}