#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a = 0, b = 0; // 두 정수
	int t = 0; // 테스트 케이스 개수
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++)
	{
		scanf("%hd%hd", &a, &b);
		printf("Case #%d: %hd + %hd = %hd\n", i, a, b, a + b);
	}
}