#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short x, y, w, h, min; // 경계선까지 최소거리
	scanf("%hd%hd%hd%hd", &x, &y, &w, &h);
	min = (x > w - x) ? w - x : x;
	min = (min > h - y) ? h - y : min;
	min = (min > y) ? y : min;
	printf("%hd", min);
}