#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int t = 0; // 테스트 케이스 개수
	short a = 0, b = 0; // 두 정수
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%hd%hd", &a, &b);
		printf("%hd\n", a + b);
	}
}