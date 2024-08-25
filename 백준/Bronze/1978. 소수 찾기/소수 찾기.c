#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n, pcnt = 0; // 소수의 개수
	scanf("%d", &n);

	for (int i = 0, num, cnt; i < n; i++)
	{
		cnt = 0;
		scanf("%d", &num);

		if (num == 1)
			continue;

		for (register int j = 2; j < num; j++)
			cnt += (num % j == 0) ? 1 : 0;
		
		pcnt += (cnt == 0) ? 1 : 0;
	}
	printf("%d", pcnt);
}