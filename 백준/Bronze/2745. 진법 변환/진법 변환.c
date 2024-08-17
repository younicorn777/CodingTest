#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	double sum = 0.0; // 각 자리수를 변환시 합
	short b, size;
	char num[30] = { '\0' };

	scanf("%s%hd", num, &b);
	size = (short)strlen(num) - 1;

	int i = 0, j = size;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			sum += (num[i++] - 48) * pow(b, j--);
		else if(num[i] >= 'A' && num[i] <= 'Z')
			sum += (num[i++] - 55) * pow(b, j--); //주의(A == 10)
	}
	printf("%.0lf", sum);
}