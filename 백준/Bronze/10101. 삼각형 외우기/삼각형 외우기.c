#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short a, b, c, sum; // 세 각, 모든 내각의 합
	scanf("%hd%hd%hd", &a, &b, &c);
	sum = a + b + c;

	if (sum == 180)
	{
		if ((a == b) && (b == c))
			printf("Equilateral");
		else if ((a == b) || (b == c) || (a == c))
			printf("Isosceles");
		else
			printf("Scalene");
	}
	else
		printf("Error");
}