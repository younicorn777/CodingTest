#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a = 2.0; // 한 변의 점의 개수
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a += pow(2, i - 1);
	printf("%.0lf", a * a);
}