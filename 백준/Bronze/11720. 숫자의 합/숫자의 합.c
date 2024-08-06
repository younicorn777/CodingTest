#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char num[100] = { '\0' };
	short n = 0, sum = 0;

	scanf("%hd", &n);
	scanf("%s", num);

	for (int i = 0; i < n; i++) {
		sum += (num[i] - 48); // 자동 형변환(정수형)
	}
	printf("%hd", sum);
}