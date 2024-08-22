#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{   
	short n, k, cnt = 0, i;  // cnt : n의 약수의 개수
	scanf("%hd%hd", &n, &k);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
			cnt++;
		if (cnt == k)
			break;
	}
	(k > cnt) ? printf("0") : printf("%d", i);
}