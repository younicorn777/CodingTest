#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char draw[100][100] = { '\0' };
	short n, cnt = 0; // 색종이 개수, 면적
	scanf("%hd", &n);

	for (short i = 0, a, b; i < n; i++) 
	{
		scanf("%hd%hd", &a, &b); // 색종이 위치

		for (int j = a; j < a + 10; j++)
			for (int k = b; k < b + 10; k++)
				draw[j][k] = 'a'; // 임의 문자 대입
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			(draw[i][j] == 'a') ? cnt++ : cnt;

	printf("%hd", cnt);
}