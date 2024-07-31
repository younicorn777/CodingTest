#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 0, b= 0, t = 0; // 두 정수 및 케이스 개수
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++)
	{
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", i, a + b);
	}
}