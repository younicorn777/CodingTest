#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b, max; // 최대값 등장위치 및 그 값
	short num[9][9];

	// 초기 max값 지정(모든 값이 0일시 대비)
	scanf("%hd", &num[0][0]);
	max = num[0][0];
	a = 0, b = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i == 0 && j == 0)
				continue;
			scanf("%hd", &num[i][j]);
			max = num[i][j] > max ? a = i, b = j, num[i][j] : max;
		}
	}
	printf("%d\n%hd %hd", max, a + 1, b + 1);
}