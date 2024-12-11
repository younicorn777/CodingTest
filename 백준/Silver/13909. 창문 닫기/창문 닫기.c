#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	long long n, i, j = 1, count = 0;
	scanf("%lld", &n);
	
	for (i = 1; i <= n; i = j * j)
	{
		count++;
		j++;
	}
	
	printf("%lld", count);
}