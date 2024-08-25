#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	
	for (register int i = 2; i <= n; i++)
	{
		while (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
	}
}