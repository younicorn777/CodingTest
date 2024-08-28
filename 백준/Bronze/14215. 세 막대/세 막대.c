#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b, c, max, sum; // 가장 긴 변, 가장 긴 변을 제외한 변들의 합
	scanf("%hd%hd%hd", &a, &b, &c);
	
	max = (a > b) ? a : b;
	max = (c > max) ? c : max;
	sum = a + b + c - max; 

	(sum > max) ? printf("%hd", sum + max) : printf("%hd", 2 * sum - 1);
}