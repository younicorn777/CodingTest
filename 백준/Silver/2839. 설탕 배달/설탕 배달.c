#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, i, j = 0; // 각각 3, 5킬로 봉지 개수
	scanf("%d", &n);

	for (i = 0; 3 * i <= n; i++)
	{
		if ((n - 3 * i) % 5 == 0)
		{
			j = (n - 3 * i) / 5;
			break;
		}
	}
	(5 * j + 3 * i == n) ? printf("%d", i + j) : printf("-1");
}