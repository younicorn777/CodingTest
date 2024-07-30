#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x = 0, n = 0, a = 0, b = 0, sum = 0; // sum : 구매한 물건의 가격과 개수로 구한 총금액
	scanf("%d%d", &x,&n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		sum += (a * b);
	}

	(sum == x) ? printf("Yes") : printf("No");
}