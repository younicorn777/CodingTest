#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char num[32] = { '\0' };
	int i = 0, b, result, remain;   //자릿수, 진법, 몫(10진수) ,나머지
	scanf("%d%d", &result, &b);

	while (result >= b)
	{
		remain = result % b; // 정수끼리의 연산에서만 %가능, 결과값 또한 정수
		result /= b;         // 정수끼리의 연산이므로, 결과값 정수

		if (remain >= 10 && remain <= 35)
			num[i++] = remain + 55;
		else if(remain >= 0 && remain <= 9)
			num[i++] = remain + 48;
	}
	
	if (result >= 10 && result <= 35)
		num[i] = result + 55;
	else if (result >= 0 && result <= 9)
		num[i] = result + 48;

	for (int j = i; j >= 0; j--)
		printf("%c", num[j]);
}