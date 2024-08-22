#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{   
	int a, b, v, day;
	scanf("%d%d%d", &a, &b, &v); // 1 <= a < b <= v
	day = (v - b) / (a - b);
	if (((v - b) % (a - b)) != 0)
		day++;
	printf("%d", day);
}