#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, i, rsum = 0, sum = 0; 
	scanf("%d", &n);

	for (i = 1; i < n; i++)
	{
		sum = 0, rsum = 0;

		for (int j = i; j > 0; j = j / 10)
			rsum = rsum + j % 10;
		
		sum = i + rsum;
		
		if (n == sum)
			break;
	}
	(i == n) ? printf("0") : printf("%d", i);
}