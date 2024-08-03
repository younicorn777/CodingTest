#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short box[100] = { 0 }; // 바구니 배열
	short n, m;             // 바구니 개수 및 공 넣는 횟수
	scanf("%hd%hd", &n, &m);

	for (short i = 0, a = 0, b = 0, c = 0; i < m; i++)
	{
		scanf("%hd%hd%hd", &a, &b, &c); 
		for (short j = (a - 1); j <= (b -1); j++)
			box[j] = c;
	}

	for (int i = 0; i < n; i++)
		printf("%hd ", box[i]);
}