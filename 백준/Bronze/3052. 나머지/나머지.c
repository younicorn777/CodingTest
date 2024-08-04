#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short remain[42] = { 0 }; // 나머지 저장
	short count = 0; // 서로 다른 나머지 개수

	for (short i = 0, a = 0; i < 10; i++) {
		scanf("%hd", &a);

		if (remain[a % 42] == 0) {
			count++;
			remain[a % 42] = 1; // 임의 상수 저장
		}
	}
	printf("%hd", count);
}