#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b, c, max, sum; // 세 변, 가장 긴 변, 세 변의 합
	while (1)
	{
		scanf("%hd%hd%hd", &a, &b, &c);
		
		if ((a == 0) && (b == 0) && (c == 0))
			break;
		
		sum = a + b + c;
		max = (a > b) ? a : b;
		max = (c > max) ? c : max;
		
		if (sum - max > max)
		{
			if ((a == b) && (b == c))
				printf("Equilateral\n");
			else if ((a == b) || (b == c) || (a == c))
				printf("Isosceles\n");
			else
				printf("Scalene\n");
		}
		else
			printf("Invalid\n");
	}
}