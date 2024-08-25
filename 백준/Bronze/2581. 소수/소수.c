#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int m, n, p = 0, psum = 0; // 등장한 소수들 중 최솟값, 소수의 합
	scanf("%d%d", &m, &n);

	for (register int i = m, cnt; i <= n; i++)
	{
		cnt = 0;
		if (i == 1)
			continue;
		
		for (register int j = 2; j < i; j++)
			cnt += (i % j == 0) ? 1 : 0;
		
		if (cnt == 0)
		{
			psum += i;
			if (psum == i)
				p = i;
		}
	}
	(psum == 0) ? printf("-1") : printf("%d\n%d", psum, p);
}