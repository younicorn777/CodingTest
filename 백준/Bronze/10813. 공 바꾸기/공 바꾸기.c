#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short box[100] = { 0 };
	short n = 0, m = 0;

	// 바구니 초기 세팅
	for (short i = 0; i < 100; i++)
		box[i] = i + 1;

	scanf("%hd%hd", &n, &m);

	// a번째와 b번째 공 교환
	for(short i = 0, a = 0, b = 0, temp = 0; i < m; i++)
	{
		scanf("%hd%hd", &a, &b);
		temp = box[a - 1];
		box[a - 1] = box[b - 1];
		box[b - 1] = temp;
	}
	
	for (short i = 0; i < n; i++)
		printf("%hd ", box[i]);
}