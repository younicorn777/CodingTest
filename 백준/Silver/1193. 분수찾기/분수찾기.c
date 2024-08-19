#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, a = 1, k = 1; 
	scanf("%d", &x);

	while (x > a)
		a += ++k;
	(k % 2 == 0) ? printf("%d/%d", x-a+k, 1-x+a) : printf("%d/%d", 1-x+a, x-a+k);
}