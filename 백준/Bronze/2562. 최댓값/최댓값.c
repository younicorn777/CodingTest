#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	short num[9] = { 0 }; 

	scanf("%hd", &num[0]);
	short max = num[0], n = 1; // 최댓값 및 최댓값이 몇번째 수인지 저장하는 변수
	
	for (int i = 1; i < 9; i++) {
		scanf("%hd", &num[i]);

		if (num[i] > max)
		{
			max = num[i]; 
			n = i + 1;
		}
	}
	printf("%hd\n%hd", max, n);
}